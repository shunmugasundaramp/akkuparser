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

#include <stdio.h>

#include "AKKUParser.hpp"

using namespace std;

static void _ParseHTTPResponse()
{
    const char* header = "HTTP/1.1 200 OK\r\n"
                        "Date: Mon, 27 Jul 2009 12:28:53 GMT\r\n"
                        "Server: Apache/2.2.14 (Win32)\r\n"
                        "Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT\r\n"
                        "Content-Length: 88\r\n"
                        "Content-Type: text/html\r\n"
                        "Connection: Closed\r\n"
                        "\r\n";

    cout << "\n***********************************\n" << __FUNCTION__ << "\n\n" << "Input:\n" << header << "\n\nOutput:\n";
    AKKU::HttpResponseHeaderParser parser;
    if (parser.parse(header, -1)) {
        cout << "Protocol:" << parser.getProtocol() << endl;
        cout << "Protocol-Version:" << parser.getProtocolVersion() << endl;
        cout << "Status-Code:" << parser.getStatusCode() << endl;
        cout << "Date:" << parser.getDate() << endl;
        cout << "Server:" << parser.getServer() << endl;
        cout << "Content-Length:" << parser.getContentLength() << endl;
        cout << "Content-Type:" << parser.getContentType() << endl;
        cout << "Connection:" << parser.getConnection() << endl;
        cout << "Unknown:" << parser.get("Unknown") << endl;
    } else {
        cout << "Parsing failed..." << endl;
    }
}

static void _ParseUriQueryString()
{
    const char* uri = "name=shunmuga&age=30&role=sse";

    cout << "\n***********************************\n" << __FUNCTION__ << "\n\n" << "Input:\n" << uri << "\n\nOutput:\n";
    AKKU::UriQueryStringParser parser;
    if (parser.parse(uri, -1)) {
        cout << "name:" << parser.get("name") << endl;
        cout << "age:" << parser.get("age") << endl;
        cout << "role:" << parser.get("role") << endl;
        cout << "experience:" << parser.get("experience") << endl;
    } else {
        cout << "Parsing failed..." << endl;
    }
}

static void _ParseUrl()
{
    const char* url = "https://github.com/search?q=user%3Ashunmugasundaramp+smartencoder#test=hello";

    cout << "\n***********************************\n" << __FUNCTION__ << "\n\n" << "Input:\n" << url << "\n\nOutput:\n";
    AKKU::UrlParser parser;
    if (parser.parse(url, -1)) {
        cout << "Protocol:" << parser.getProtocol() << endl;
        cout << "HostName:" << parser.getHostName() << endl;
        cout << "Path:" << parser.getPath() << endl;
        cout << "QueryString:" << parser.getQueryString() << endl;
        cout << "HashValue:" << parser.getHashValue() << endl;
    } else {
        cout << "Parsing failed..." << endl;
    }
}

int main(int argc, char** argv)
{
    _ParseHTTPResponse();

    _ParseUriQueryString();

    _ParseUrl();

    return 0;
}

