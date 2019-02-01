#!/bin/bash

# ****************************************************************************
# * Copyright (c) 2018 by Onnet Systems, Inc.
# * Description: This build system is used to compile the Test Client source
# * Author(s): Shunmuga (shunmuga@onnetsystems.net)
# ****************************************************************************


LIBRARY_PATH=../lib/linux
#LIBRARY_PATH=../lib

#STATIC_LINKING="Y"
STATIC_LINKING="N"

if [ $STATIC_LINKING == "Y" ]; then
LIBRARIES="-lONN_ONVIFClient -lpthread -lrt"
else
LIBRARIES="-lONN_ONVIFClient"
fi

declare -a CPPFILES=(	"usage.cpp")

prepareOutDir() {
	rm -fr objs/*
	mkdir -p objs
	if [ $STATIC_LINKING != "Y" ]; then
		cp -P $LIBRARY_PATH/*.* objs
	fi
}

cppCompile() {
	for i in "${CPPFILES[@]}"
	do
		INFILE=$i
		OUTFILE=${i//.cpp/.exe}
		echo -e '\e[96m*** Compiling '$INFILE'\e[0m'
		g++ src/$INFILE -o objs/$OUTFILE -I../includes -D_PC_LINUX_ -std=c++11 -L$LIBRARY_PATH $LIBRARIES
	done
}

prepareOutDir
cppCompile
