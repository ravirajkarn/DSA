cmake_minimum_required(VERSION 4.0)
project(binary_search CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(binary_search src/binary_search.cpp)
target_include_directories(binary_search 
    PRIVATE 
    ${CMAKE_SOURCE_DIR}/inc
)

add_executable(leetCode_test test/leetCode_test.cpp)
target_include_directories(leetCode_test 
    PRIVATE 
    ${CMAKE_SOURCE_DIR}/inc
)
target_link_libraries(leetCode_test 
    PRIVATE 
    GTest::gtest 
    GTest::gtest_main
)

enable_testing()
include(GoogleTest)

gtest_discover_tests(leetCode_test)