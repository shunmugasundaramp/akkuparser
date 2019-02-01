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
  * @file AKKUParser.hpp
  * @brief Declaration of AKKUParser C-Style methods and also include the CPP headers as well
  * @author Shunmuga (ssundaramp@outlook.com)
  *
  */

#include "HttpResponseHeaderParser.hpp"
#include "UriQueryStringParser.hpp"
#include "UrlParser.hpp"

#pragma once

#ifndef _AKKUParser_hpp_
#define _AKKUParser_hpp_

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/// @brief C-Style api to create a UriQueryStringParser object
/// @param[in] str - input string to parse
/// @param[in] len - length of the input string
/// @return Parser object to be returned, otherwise nullptr
void* AKKU_CreateUriQueryStringParser(const char *str, int len);

/// @brief C-Style api to query/retrieve the value by given variable name
/// @param[in] ctx - Parser object which was created by AKKU_CreateUriQueryStringParser()
/// @param[in] name - variable name
/// @return value of the variable if present, otherwise ""
char* AKKU_GetUriQueryStringVariable(void* ctx, const char *name);

/// @brief C-Style api to destory the parser object
/// @param[in] ctx - Parser object which was created by AKKU_CreateUriQueryStringParser()
void  AKKU_DestroyUriQueryStringParser(void* ctx);

/// @brief C-Style api to create a HttpResponseHeaderParser object
/// @param[in] str - input string to parse
/// @param[in] len - length of the input string
/// @return Parser object to be returned, otherwise nullptr
void* AKKU_CreateHttpResponseHeaderParser(const char *str, int len);

/// @brief C-Style api to query/retrieve the value by given response header
/// @param[in] ctx - Parser object which was created by AKKU_CreateHttpResponseHeaderParser()
/// @param[in] name - header name name
/// @return value of the header if present, otherwise ""
char* AKKU_GetHttpResponseHeaderVariable(void* ctx, const char *name);

/// @brief C-Style api to destory the parser object
/// @param[in] ctx - Parser object which was created by AKKU_CreateHttpResponseHeaderParser()
void  AKKU_DestroyHttpResponseHeaderParser(void* ctx);

/// @brief C-Style api to create a UrlStringParser object
/// @param[in] str - input string to parse
/// @param[in] len - length of the input string
/// @return Parser object to be returned, otherwise nullptr
void* AKKU_CreateUrlParser(const char *str, int len);

/// @brief C-Style api to query/retrieve the Protocol type
/// @param[in] ctx - Parser object which was created by AKKU_CreateUrlParser()
/// @return protocol value if present, otherwise ""
char* AKKU_GetUrlProtocol(void* ctx);

/// @brief C-Style api to query/retrieve the HostName
/// @param[in] ctx - Parser object which was created by AKKU_CreateUrlParser()
/// @return hostname if present, otherwise ""
char* AKKU_GetUrlHostName(void* ctx);

/// @brief C-Style api to query/retrieve the Path
/// @param[in] ctx - Parser object which was created by AKKU_CreateUrlParser()
/// @return path value if present, otherwise ""
char* AKKU_GetUrlPath(void* ctx);

/// @brief C-Style api to destory the parser object
/// @param[in] ctx - Parser object which was created by AKKU_CreateUrlParser()
void  AKKU_DestroyUrlParser(void* ctx);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //_AKKUParser_hpp_

