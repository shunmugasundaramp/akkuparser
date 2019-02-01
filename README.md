
                   AKKU Parser, Release 2.0.0

This is AKKU Parser, a C++ library for parsing HTTP Response Header
and HTTP Request Query String, written by Shunmuga Sundaram.  It is
a independent source which should not having any other thirdparty
software references

Currently it is having a support to compile with GCC Compiler.
Hopefully it will come for other compilers too.

AKKU Parser is free software.  You may copy, distribute, and modify
it under the terms of the License contained in the file COPYING
distributed with this package.  This license is the same as the
Apache Consortium license.

If you are building AKKU Parser, you need to run a makefile that
generates the library akkuparser.a and also you will get a binary
akkuparser with present testcode


# AKKUParser
Light weight parser to parse HTTP Responses, URL and URI QueryString

1. Easy to include anywhere
2. No dependencies
3. Simpler & Modular
4. Extend this parsing based on our requirement easily

# Usage
## In Linux

### To Compile 

g++ HttpResponseHeaderParser.cpp -c -o HttpResponseHeaderParser.o
g++ UriQueryStringParser.cpp -c -o UriQueryStringParser.o
g++ UrlParser.cpp -c -o UrlParser.o

g++ usage.cpp HttpResponseHeaderParser.o UriQueryStringParser.o UrlParser.o

### To Run

./a.out

## In Windows
### To Compile

winbuild.bat

### To Run

./usage.exe

# Output
```
***********************************
_ParseHTTPResponse

Input:
======
HTTP/1.1 200 OK
Date: Mon, 27 Jul 2009 12:28:53 GMT
Server: Apache/2.2.14 (Win32)
Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT
Content-Length: 88
Content-Type: text/html
Connection: Closed

Output:
=======
Protocol:HTTP
Protocol-Version:1.1
Status-Code:200
Date:Mon, 27 Jul 2009 12:28:53 GMT
Server:Apache/2.2.14 (Win32)
Content-Length:88
Content-Type:text/html
Connection:Closed
Unknown:

***********************************
_ParseUriQueryString

Input:
======
name=shunmuga&age=30&role=sse

Output:
=======
name:shunmuga
age:30
role:sse
experience:

***********************************
_ParseUrl

Input:
======
https://github.com/search?q=user%3Ashunmugasundaramp+smartencoder#test=hello

Output:
=======
Protocol:https://
HostName:github.com
Path:/search
QueryString:?q=user%3Ashunmugasundaramp+smartencoder
HashValue:#test=hello
```