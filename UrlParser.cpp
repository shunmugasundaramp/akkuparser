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

/**
  *
  * @file UrlParser.cpp
  * @brief Definition of UrlParser and its supported methods
  * @author Shunmuga (ssundaramp@outlook.com)
  *
  */

#include "UrlParser.hpp"

using namespace AKKU;

UrlParser::UrlParser()
{
}

UrlParser::~UrlParser()
{
}

bool UrlParser::Parse()
{
    if (m_data.empty()) {
        return false;
    }
    int start = 0, len = 0;
    string value;
    len = m_data.find(":", start);
    len += 3;
    value.assign(m_data, start, len);
    Push("protocol",value);
    start += len;
    len = m_data.find("/",start) - start;
    if (len > 0) {
        value.assign(m_data, start, len);
        Push("hostname",value);
    } else {
        value.assign(m_data, start, m_data.length() - start);
        Push("hostname",value);
    }

    len = m_data.find("#");
    if (len > 0) {
        value.assign(m_data, len, m_data.length() - len);
        Push("hash",value);
    } else {
        value.assign(m_data);
        Push("hash","");
    }

    start = Get("hash").length();
    len = m_data.find("?");
    if (len > 0) {
        value.assign(m_data, len, m_data.length() - len - start);
        Push("query",value);
    } else {
        value.assign(m_data);
        Push("query","");
    }

    start = Get("protocol").length() + Get("hostname").length();
    value.assign(m_data, start, m_data.length() - start);
    len = value.find("/");
    if (len >= 0) {
        value.assign(m_data, start + len, m_data.length() - start - len - Get("hash").length() - Get("query").length());
        Push("path",value);
        start += len;
    } else {
        value.assign(m_data);
        Push("path","");
    }

    return true;
}

bool UrlParser::Validate(const char* buff, int &len)
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

bool UrlParser::Parse(const char* buff, int len)
{
    // have to Get the length by parsing the buff until reached to '0'
    if (len == 0 || (len < 0 && true != Validate(buff, len))) {
        return false;
    }
    m_data.assign(buff, len);
    return this->Parse();
}


// For C Style Users /////
AKKU_APIS_DEFINITION(CreateUrlParser, void*, (const char *str, int len))
{
    UrlParser *o = new UrlParser();
    if (false == o->Parse(str, len)) {
        delete o;
        return NULL;
    }
    return static_cast<void*>(o);
}

AKKU_APIS_DEFINITION(GetUrlProtocol, char*, (void* ctx))
{
    if (ctx == NULL) return const_cast<char*>(string().c_str());
    UrlParser *o = static_cast<UrlParser*>(ctx);
    return const_cast<char*>(o->Get("protocol").c_str());
}

AKKU_APIS_DEFINITION(GetUrlHostName, char*, (void* ctx))
{
    if (ctx == NULL) return const_cast<char*>(string().c_str());
    UrlParser *o = static_cast<UrlParser*>(ctx);
    return const_cast<char*>(o->Get("host").c_str());
}

AKKU_APIS_DEFINITION(GetUrlPath, char*, (void* ctx))
{
    if (ctx == NULL) return const_cast<char*>(string().c_str());
    UrlParser *o = static_cast<UrlParser*>(ctx);
    return const_cast<char*>(o->Get("path").c_str());
}

AKKU_APIS_DEFINITION(DestroyUrlParser, void, (void* ctx))
{
    if (ctx == NULL) return;
    UrlParser *o = static_cast<UrlParser*>(ctx);
    delete o;
}

