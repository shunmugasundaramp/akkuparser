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
  * @file UrlParser.hpp
  * @brief Declaration of UrlParser and its supported classes
  * @author Shunmuga (ssundaramp@outlook.com)
  *
  */

#include "CoreParser.hpp"

#pragma once

#ifndef _UrlParser_h_
#define _UrlParser_h_

#ifdef __cplusplus

namespace AKKU {

/// @brief Declaration of UrlParser
class UrlParser : public CoreParser
{
    public:
        /// @brief Construct a new Url Parser
        UrlParser();

        /// @brief Destroy the Url Parser
        ~UrlParser();

        /// @brief Do the parsing functionality
        /// @param[in] buff - input data
        /// @param[in] len - length of the input data
        /// @return true if call success, otherwise false
        bool Parse(const char* buff, int len) final;

        // For easy handling, below methods are used to get generic header fields

        /// @brief Get the Protocol
        /// @return string 
        string GetProtocol() {
            return Get("protocol");
        }

        /// @brief Get the Host Name
        /// @return string 
        string GetHostName() {
            return Get("hostname");
        }

        /// @brief Get the Path
        /// @return string 
        string GetPath() {
            return Get("path");
        }

        /// @brief Get the Query String
        /// @return string 
        string GetQueryString() {
            return Get("query");
        }

        /// @brief Get the Hash Value
        /// @return string 
        string GetHashValue() {
            return Get("hash");
        }

    private:
        bool Validate(const char* buff, int &len);
        bool Parse ();

    private:
        string m_data;

}; // class UrlParser

}; // namespace AKKU

#endif //__cplusplus

#endif //_UrlParser_h_

