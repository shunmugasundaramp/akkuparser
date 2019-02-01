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

#include "HttpResponseHeaderParser.hpp"

using namespace AKKU;

/// HttpResponseHeaderParser ////////////////////////////////////
HttpResponseHeaderParser::HttpResponseHeaderParser()
{
}
HttpResponseHeaderParser::~HttpResponseHeaderParser()
{
}
bool HttpResponseHeaderParser::parse ()
{
   if (this->data.empty()) {
      return false;
   }
   int start = 0, len = 0;
   string line, value, key;
   // Parse first line
   if (linebyline(start, len)) {
      line.assign(this->data, start, len);
      {
         int start = 0, len;

         len = line.find("/", start) - start;
         value.assign(line, start, len);
         push("Protocol", value);
         start = start + len + 1/*skip /*/;

         len = line.find(" ", start) - start;
         value.assign(line, start, len);
         push("Protocol-Version", value);
         start = start + len + 1/*skip space*/;

         len = line.find(" ", start) - start;
         value.assign(line, start, len);
         push("Status-Code", value);
      }
      start = start + len + 2/*skip \r\n*/;
   }

   // Parse further lines
   while (linebyline(start, len)) {
      line.assign(this->data, start, len);
      {
         int start = 0, len;
         len = line.find(":", start) - start;
         key.assign(line, start, len);
         start = start + len + 1;
         if (line[start] == ' ') {
            start += 1;
         }
         len = line.find("\r\n", start) - start;
         value.assign(line, start, len);
         push(key, value);
      }
      start = start + len + 2/*skip \r\n*/;
   }

   return true;
}
bool HttpResponseHeaderParser::linebyline(int start, int &len)
{
   return 0 < (len = this->data.find("\r\n", start) - start) ? true : false;
}
bool HttpResponseHeaderParser::validate (const char* buff, int &len)
{
   int iterator = 0, terminates = 0;
   while(terminates != 4 && buff[iterator] != '\0') {
      terminates = (buff[iterator] == '\r' || buff[iterator] == '\n' || buff[iterator] == '\r' || buff[iterator] == '\n') ? terminates+1 : 0;
      if (len != -1 && iterator > len) {
         return false;
      };
      ++iterator;
   }
   len = iterator;
   return true;
}
bool HttpResponseHeaderParser::parse (const char* buff, int len)
{
   // have to get the length by parsing the buff until reached to \r\n\r\n
   if (len == 0 || (len < 0 && true != validate(buff, len))) {
      return false;
   }
   this->data.assign(buff, len);
   return this->parse();
}


/// For C Style Users /////
AKKU_APIS_DEFINITION(CreateHttpResponseHeaderParser, void*, (const char *str, int len))
{
   HttpResponseHeaderParser *o = new HttpResponseHeaderParser();
   if (false == o->parse(str, len)) {
      delete o;
      return NULL;
   }
   return static_cast<void*>(o);
}

AKKU_APIS_DEFINITION(GetHttpResponseHeaderVariable, char*, (void* ctx, const char *name))
{
   if (ctx == NULL) return const_cast<char*>(string().c_str());
   HttpResponseHeaderParser *o = static_cast<HttpResponseHeaderParser*>(ctx);
   return const_cast<char*>(o->get(name).c_str());
}

AKKU_APIS_DEFINITION(DestroyHttpResponseHeaderParser, void, (void* ctx))
{
   if (ctx == NULL) return;
   HttpResponseHeaderParser *o = static_cast<HttpResponseHeaderParser*>(ctx);
   delete o;
}

