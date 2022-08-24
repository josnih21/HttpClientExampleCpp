cmake_minimum_required(VERSION 3.9)
project(HttpClient_CppRestSDK)

find_package(cpprestsdk REQUIRED)
find_package(Boost REQUIRED system)

add_executable(HttpClient_CppRestSDK main.cpp HttpClient.cpp)
target_link_libraries(HttpClient_CppRestSDK PRIVATE cpprestsdk::cpprest ${Boost_SYSTEM_LIBRARY})

