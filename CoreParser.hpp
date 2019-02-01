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

#ifdef __cplusplus
#include <iostream>
#include <map>
#include <string>

#pragma once

#ifndef _CoreParser_h_
#define _CoreParser_h_

#define AKKU_APIS_DEFINITION(_API_, _RET_, _ARG_) extern "C" _RET_ AKKU_##_API_ _ARG_

using namespace std;
namespace AKKU {
class CoreParser
{
   public:
      CoreParser() {}
      virtual ~CoreParser() {
         clear();
      }
      // Override with your requirement
      virtual bool parse (const char* buff, int len) = 0;
      bool push(const string key, const string value) {
         elements[key] = value;
         return true;
      }
      const string get(const string key) {
         return elements[key];
      }
      bool clear() {
         elements.clear();
         return true;
      }
   private:
      map<string, string> elements;
};
};
#endif //_CoreParser_h_

#endif //__cplusplus

