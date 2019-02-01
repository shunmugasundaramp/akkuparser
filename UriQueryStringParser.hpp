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
  * @file UriQueryStringParser.hpp
  * @brief Declaration of UriQueryStringParser and its supported classes
  * @author Shunmuga (ssundaramp@outlook.com)
  *
  */

#include "CoreParser.hpp"

#pragma once

#ifndef _UriQueryStringParser_hpp_
#define _UriQueryStringParser_hpp_

#ifdef __cplusplus

namespace AKKU {

/// @brief Declaration of UriQueryStringParser
class UriQueryStringParser : public CoreParser
{
    public:
        /// @brief Construct a new Uri Query String Parser object
        UriQueryStringParser();

        /// @brief Destroy the Uri Query String Parser object
        ~UriQueryStringParser();

        /// @brief Do the parsing functionality
        /// @param[in] buff - input data
        /// @param[in] len - length of the input data
        /// @return true if call success, otherwise false
        bool Parse(const char* buff, int len) final;

    private:
        bool Validate(const char* buff, int &len);
        bool Parse ();
        bool Linebyline(int start, int &len);

    private:
        string m_data;

}; // class UriQueryStringParser

}; // namespace AKKU

#endif //__cplusplus

#endif //_UriQueryStringParser_hpp_

