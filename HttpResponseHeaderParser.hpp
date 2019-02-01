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

#include "CoreParser.hpp"

#pragma once

#ifndef _HttpResponseHeaderParser_h_
#define _HttpResponseHeaderParser_h_

#ifdef __cplusplus
namespace AKKU {
class HttpResponseHeaderParser : public CoreParser
{
   public:
      HttpResponseHeaderParser();
      ~HttpResponseHeaderParser();
      // Override Method
      bool parse (const char* buff, int len);

      // For easy handling, below methods are used to get generic header fields
      string getDate() {
         return get("Date");
      }
      string getContentLength() {
         return get("Content-Length");
      }
      string getContentType() {
         return get("Content-Type");
      }
      string getProtocol() {
         return get("Protocol");
      }
      string getProtocolVersion() {
         return get("Protocol-Version");
      }
      string getStatusCode() {
         return get("Status-Code");
      }
      string getServer() {
         return get("Server");
      }
      string getConnection() {
         return get("Connection");
      }
   private:
      bool validate(const char* buff, int &len);
      bool parse ();
      bool linebyline(int start, int &len);
   private:
      string data;
};
};
#endif //__cplusplus

#endif //_HttpResponseHeaderParser_h_

