/*
Copyright [2016] [ssundaramp@outlook.com]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "UrlParser.hpp"

using namespace AKKU;

/// UriQueryStringParser ////////////////////////////////////
UrlParser::UrlParser()
{
}
UrlParser::~UrlParser()
{
}
bool UrlParser::parse ()
{
   if (this->data.empty()) {
      return false;
   }
   int start = 0, len = 0;
   string value;
   len = this->data.find(":", start);
   len += 3;
   value.assign(this->data, start, len);
   push("protocol",value);
   start += len;
   len = this->data.find("/",start) - start;
   if (len > 0) {
      value.assign(this->data, start, len);
      push("hostname",value);
   } else {
      value.assign(this->data, start, this->data.length() - start);
      push("hostname",value);
   }

   len = this->data.find("#");
   if (len > 0) {
      value.assign(this->data, len, this->data.length() - len);
      push("hash",value);
   } else {
      value.assign(this->data);
      push("hash","");
   }

   start = get("hash").length();
   len = this->data.find("?");
   if (len > 0) {
      value.assign(this->data, len, this->data.length() - len - start);
      push("query",value);
   } else {
      value.assign(this->data);
      push("query","");
   }

   start = get("protocol").length() + get("hostname").length();
   value.assign(this->data, start, this->data.length() - start);
   len = value.find("/");
   if (len >= 0) {
      value.assign(this->data, start + len, this->data.length() - start - len - get("hash").length() - get("query").length());
      push("path",value);
      start += len;
   } else {
      value.assign(this->data);
      push("path","");
   }

   return true;
}
bool UrlParser::validate (const char* buff, int &len)
{
   int iterator = 0;
   while(buff[iterator] != '\0') {
      if (len != -1 && iterator > len) {
         return false;
      };
      ++iterator;
   }
   len = iterator;
   return true;
}
bool UrlParser::parse (const char* buff, int len)
{
   // have to get the length by parsing the buff until reached to '0'
   if (len == 0 || (len < 0 && true != validate(buff, len))) {
      return false;
   }
   this->data.assign(buff, len);
   return this->parse();
}


/// For C Style Users /////
AKKU_APIS_DEFINITION(CreateUrlParser, void*, (const char *str, int len))
{
   UrlParser *o = new UrlParser();
   if (false == o->parse(str, len)) {
      delete o;
      return NULL;
   }
   return static_cast<void*>(o);
}

AKKU_APIS_DEFINITION(GetUrlProtocol, char*, (void* ctx))
{
   if (ctx == NULL) return const_cast<char*>(string().c_str());
   UrlParser *o = static_cast<UrlParser*>(ctx);
   return const_cast<char*>(o->get("protocol").c_str());
}

AKKU_APIS_DEFINITION(GetUrlHostName, char*, (void* ctx))
{
   if (ctx == NULL) return const_cast<char*>(string().c_str());
   UrlParser *o = static_cast<UrlParser*>(ctx);
   return const_cast<char*>(o->get("host").c_str());
}

AKKU_APIS_DEFINITION(GetUrlPath, char*, (void* ctx))
{
   if (ctx == NULL) return const_cast<char*>(string().c_str());
   UrlParser *o = static_cast<UrlParser*>(ctx);
   return const_cast<char*>(o->get("path").c_str());
}

AKKU_APIS_DEFINITION(DestroyUrlParser, void, (void* ctx))
{
   if (ctx == NULL) return;
   UrlParser *o = static_cast<UrlParser*>(ctx);
   delete o;
}

