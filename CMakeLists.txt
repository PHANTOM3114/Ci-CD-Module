cmake_minimum_required(VERSION 3.20)
project(CiCD_Module CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost REQUIRED COMPONENTS system)

if(NOT Boost_FOUND)
    find_package(asio CONFIG REQUIRED)
endif()

add_executable(cicd_module main.cc)

if(Boost_FOUND)
    target_link_libraries(cicd_module PRIVATE Boost::system)
    target_compile_definitions(cicd_module PRIVATE BOOST_ASIO)
else()
    target_link_libraries(cicd_module PRIVATE asio::asio)
    target_compile_definitions(cicd_module PRIVATE ASIO_STANDALONE)
endif()
