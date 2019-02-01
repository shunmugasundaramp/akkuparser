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
  * @file UriQueryStringParser.cpp
  * @brief Definition of UriQueryStringParser and its supported methods
  * @author Shunmuga (ssundaramp@outlook.com)
  *
  */

#include "UriQueryStringParser.hpp"

using namespace AKKU;

UriQueryStringParser::UriQueryStringParser()
{
}

UriQueryStringParser::~UriQueryStringParser()
{
}

bool UriQueryStringParser::Parse()
{
    if (m_data.empty()) {
        return false;
    }
    int start = 0, len = 0;
    string line, value, key;
    // Parse further lines
    while (Linebyline(start, len)) {
        line.assign(m_data, start, len);
        {
            int start = 0, len;
            len = line.find("=", start) - start;
            key.assign(line, start, len);
            start = start + len + 1;
            if (line[start] == ' ') {
                start += 1;
            }
            len = line.find("&", start) - start;
            value.assign(line, start, len);
            Push(key.c_str(), value);
        }
        start = start + len + 1/*skip &*/;
    }

    return true;
}

bool UriQueryStringParser::Linebyline(int start, int &len)
{
    return 0 < (len = m_data.find("&", start) - start) ? true : false;
}

bool UriQueryStringParser::Validate(const char* buff, int &len)
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

bool UriQueryStringParser::Parse(const char* buff, int len)
{
    // have to get the length by parsing the buff until reached to '0'
    if (len == 0 || (len < 0 && true != Validate(buff, len))) {
        return false;
    }
    m_data.assign(buff, len);
    // notate the end of query string
    m_data += "&";
    return this->Parse();
}


// For C Style Users /////
AKKU_APIS_DEFINITION(CreateUriQueryStringParser, void*, (const char *str, int len))
{
    UriQueryStringParser *o = new UriQueryStringParser();
    if (false == o->Parse(str, len)) {
        delete o;
        return NULL;
    }
    return static_cast<void*>(o);
}

AKKU_APIS_DEFINITION(GetUriQueryStringVariable, char*, (void* ctx, const char *name))
{
    if (ctx == NULL) return const_cast<char*>(string().c_str());
    UriQueryStringParser *o = static_cast<UriQueryStringParser*>(ctx);
    return const_cast<char*>(o->Get(name).c_str());
}

AKKU_APIS_DEFINITION(DestroyUriQueryStringParser, void, (void* ctx))
{
    if (ctx == NULL) return;
    UriQueryStringParser *o = static_cast<UriQueryStringParser*>(ctx);
    delete o;
}

