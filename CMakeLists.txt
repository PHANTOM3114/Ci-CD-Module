cmake_minimum_required(VERSION 3.20)

include(FetchContent)

project(CiCD_Module CXX)

FetchContent_Declare(httplib SYSTEM
        GIT_REPOSITORY https://github.com/yhirose/cpp-httplib
        GIT_TAG a609330e4c6374f741d3b369269f7848255e1954 # v0.14.1
        GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(httplib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(nlohmann_json REQUIRED)
find_package(sdbus-c++ REQUIRED)

add_executable(cicd_module main.cc
        src/fetcher.cpp
)

target_include_directories(cicd_module PRIVATE
        ${HTTPLIB_INCLUDE_DIR}
        include
)

target_link_libraries(cicd_module PRIVATE
        OpenSSL::SSL
        OpenSSL::Crypto
        ZLIB::ZLIB
        httplib
        Boost::system
        nlohmann_json::nlohmann_json
        SDBusCpp::sdbus-c++
)

target_compile_definitions(cicd_module PRIVATE CPPHTTPLIB_OPENSSL_SUPPORT)