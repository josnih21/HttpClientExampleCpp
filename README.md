# About this project
This project aims to show a simple example of how to use a *HttpClient* in C++ by using the microsoft `cpprestsdk` you can find two examples of different type of http requests and how to handle it.

# About CPPRestSDK lib
It's a library developed by microsoft to build http servers and http clients, you can find more information about it in the [official repository](https://github.com/microsoft/cpprestsdk)

# Getting Started

1. **Install the cpprestsdk you can do it by using directly apt repositories if you're using Debian based Linux distribution**\
 `sudo apt-get install libcpprest-dev`
 
2. **Run CMakeList to build the project makefile by doing**\
  `cmake .` to build from your root directory\
    If CMake shows an error related to missing the variable *CMAKE_PREFIX_PATH* add the following flag to the CMake execution\
  `cmake . -DCMAKE_PREFIX_PATH=/usr/lib/<your-system-architecture-folder>/cmake` 
3. **Run makefile to generate the executable**\
  `make`
4. **Run the generated executable to test example the code**\
   `./HttpClient_CppRestSDK`
