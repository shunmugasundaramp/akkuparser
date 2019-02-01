@echo off
REM ****************************************************************************
REM * Copyright (c) 2018 by Onnet Systems, Inc.
REM * Description: This build system is used to compile the Test Client source
REM * Author(s): Shunmuga (shunmuga@onnetsystems.net)
REM ****************************************************************************

SETLOCAL
SETLOCAL ENABLEDELAYEDEXPANSION

set FILES[0].src=HttpResponseHeaderParser.cpp
set FILES[0].obj=HttpResponseHeaderParser.obj

set FILES[1].src=UriQueryStringParser.cpp
set FILES[1].obj=UriQueryStringParser.obj

set FILES[2].src=UrlParser.cpp
set FILES[2].obj=UrlParser.obj

set FILES[3].src=usage.cpp
set FILES[3].obj=usage.obj

rem ****************************************************************
rem DON'T TOUCH THE BELOW PART UNTIL OTHERWISE YOU ARE FAMILIAR WITH
rem THIS BUILD SYSTEM
set "count=0"
:FindFileLength
if defined FILES[%count%].src (
	set /a "count+=1"
	GOTO :FindFileLength
)
set /a "count-=1"

md objs
del /F /Q objs\*.exe
del /F /Q objs\*.obj

set "OBJS="
for /l %%n in (0,1,%count%) do (
	cl /c /EHsc %CD%\!FILES[%%n].src! /Foobjs/!FILES[%%n].obj! /I%CD%
	SET OBJS=!OBJS! objs/!FILES[%%n].obj!
)

link /OUT:objs/usage.exe %OBJS%

rem ****************************************************************

ENDLOCAL