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

#ifndef _UrlParser_h_
#define _UrlParser_h_

#ifdef __cplusplus
namespace AKKU {
class UrlParser : public CoreParser
{
   public:
      UrlParser();
      ~UrlParser();
      // Override Method
      bool parse (const char* buff, int len);

      // For easy handling, below methods are used to get generic header fields
      string getProtocol() {
         return get("protocol");
      }
      string getHostName() {
         return get("hostname");
      }
      string getPath() {
         return get("path");
      }
      string getQueryString() {
         return get("query");
      }
      string getHashValue() {
         return get("hash");
      }

   private:
      bool validate(const char* buff, int &len);
      bool parse ();
   private:
      string data;
};
};
#endif //__cplusplus

#endif //_UrlParser_h_

