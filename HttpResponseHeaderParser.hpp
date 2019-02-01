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
  * @file HttpResponseHeaderParser.hpp
  * @brief Declaration of HttpResponseHeaderParser and its supported classes
  * @author Shunmuga (ssundaramp@outlook.com)
  *
  */

#include "CoreParser.hpp"

#pragma once

#ifndef _HttpResponseHeaderParser_hpp_
#define _HttpResponseHeaderParser_hpp_

#ifdef __cplusplus
namespace AKKU {

/// @brief Declaration of HttpResponseHeaderParser
class HttpResponseHeaderParser : public CoreParser
{
    public:
        /// @brief Construct a new Http Response Header Parser object
        HttpResponseHeaderParser();

        /// @brief Destroy the Http Response Header Parser object
        ~HttpResponseHeaderParser();

        /// @brief Do the parsing functionality
        /// @param[in] buff - input data
        /// @param[in] len - length of the input data
        /// @return true if call success, otherwise false
        bool Parse(const char* buff, int len) final;

        // For easy handling, below methods are used to get generic header fields

        /// @brief Get the Date value
        /// @return string 
        string GetDate() {
            return Get("Date");
        }

        /// @brief Get the Content Length
        /// @return string 
        string GetContentLength() {
            return Get("Content-Length");
        }

        /// @brief Get the Content Type
        /// @return string 
        string GetContentType() {
            return Get("Content-Type");
        }

        /// @brief Get the Protocol
        /// @return string 
        string GetProtocol() {
            return Get("Protocol");
        }

        /// @brief Get the Protocol Version
        /// @return string 
        string GetProtocolVersion() {
            return Get("Protocol-Version");
        }

        /// @brief Get the Status Code
        /// @return string 
        string GetStatusCode() {
            return Get("Status-Code");
        }

        /// @brief Get the Server
        /// @return string 
        string GetServer() {
            return Get("Server");
        }

        /// @brief Get the Connection
        /// @return string 
        string GetConnection() {
            return Get("Connection");
        }

    private:
        bool Validate(const char* buff, int &len);
        bool Parse();
        bool Linebyline(int start, int &len);

    private:
        string m_data;

}; // class HttpResponseHeaderParser

}; // namespace AKKU

#endif //__cplusplus

#endif //_HttpResponseHeaderParser_hpp_

