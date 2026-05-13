cmake_minimum_required(VERSION 3.14)
project(CalcSampleTDD-Cpp)

set(CMAKE_CXX_STANDARD 17)

# include(FetchContent)
# FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
# )
# FetchContent_MakeAvailable(googletest)


# GoogleTest
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/googletest) #

enable_testing()

add_executable(calc_sample_test test/calc_sample_test.cpp)
target_include_directories(calc_sample_test PRIVATE src)
target_link_libraries(calc_sample_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(calc_sample_test)
