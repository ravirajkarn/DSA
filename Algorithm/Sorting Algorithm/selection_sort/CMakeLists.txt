cmake_minimum_required(VERSION 4.0)
project(selection_sort CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cpp)
target_include_directories(${PROJECT_NAME} 
    PRIVATE 
    ${CMAKE_SOURCE_DIR}/inc
)

set(TEST1 gemini_test) # <-- name of test
add_executable(${TEST1} test/${TEST1}.cpp)
target_include_directories(${TEST1} 
    PRIVATE 
    ${CMAKE_SOURCE_DIR}/inc
)
target_link_libraries(${TEST1} 
    PRIVATE 
    GTest::gtest 
    GTest::gtest_main
)

enable_testing()
include(GoogleTest)

gtest_discover_tests(${TEST1})