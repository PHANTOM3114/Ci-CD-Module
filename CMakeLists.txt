cmake_minimum_required(VERSION 3.20)
project(CiCD_Module CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(nlohmann_json REQUIRED)

find_path(HTTPLIB_INCLUDE_DIR "httplib.h" REQUIRED)

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
        Boost::system
        nlohmann_json::nlohmann_json
)

target_compile_definitions(cicd_module PRIVATE CPPHTTPLIB_OPENSSL_SUPPORT)