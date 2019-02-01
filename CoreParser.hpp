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
  * @file CoreParser.hpp
  * @brief Declaration of CoreParser and its supported classes
  * @author Shunmuga (ssundaramp@outlook.com)
  *
  */

#ifdef __cplusplus
#include <iostream>
#include <map>
#include <string>

#pragma once

#ifndef _CoreParser_hpp_
#define _CoreParser_hpp_

#define AKKU_APIS_DEFINITION(_API_, _RET_, _ARG_) extern "C" _RET_ AKKU_##_API_ _ARG_

using namespace std;

namespace AKKU {

/// @brief Declaration of CoreParse abstract class
class CoreParser
{
    public:
        /// @brief Construct a new Core Parser object
        CoreParser() {}

        /// @brief Destroy the Core Parser object
        virtual ~CoreParser() {
            Clear();
        }

        /// @brief Do the parsing functionality which should be implemented in all the derived classess
        /// @param[in] buff - input data
        /// @param[in] len - length of the input data
        /// @return true if call success, otherwise false
        virtual bool Parse (const char* buff, int len) = 0;

        /// @brief Method to push the key-value pair into the storage container
        /// @param[in] key - key of the pair
        /// @param[in] value - value of the pair
        /// @return true if call success, otherwise false
        bool Push(const char* key, string& value) {
            m_elements[key] = value;
            return true;
        }

        /// @brief Method to push the key-value pair into the storage container
        /// @param[in] key - key of the pair
        /// @param[in] value - value of the pair
        /// @return true if call success, otherwise false
        bool Push(const char* key, const char* value) {
            string v = value;
            return Push(key, v);
        }

        /// @brief Method to retrieve the value from the given key
        /// @param[in] key - input key
        /// @return value of the key if present, otherwise empty string
        const string Get(const char* key) {
            return m_elements[key];
        }

        /// @brief Flush the storage containter
        /// @return true if call success, otherwise false
        bool Clear() {
            m_elements.clear();
            return true;
        }

    private:
        map<string, string> m_elements;
}; // class CoreParser

}; // namespace AKKU

#endif //_CoreParser_hpp_

#endif //__cplusplus

