cmake_minimum_required(VERSION 3.15)
project(Prime_Number CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

execute_process(
        COMMAND conan install . --build=missing --profile=profile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE CONAN_RESULT
)
if(NOT ${CONAN_RESULT} EQUAL 0)
    message(FATAL_ERROR "Conan install failed with error code ${CONAN_RESULT}") 
endif()

include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

add_executable(temp src/temp.cpp)
target_link_libraries(temp PRIVATE fmt::fmt gtest::gtest)
target_include_directories(temp PRIVATE ${CMAKE_SOURCE_DIR}/include)
