cmake_minimum_required(VERSION 2.6)

project(gflags-example)

find_package(gflags)

add_executable(gflags-example example.cpp)

target_link_libraries(gflags-example gflags)

add_test(NAME printing_version COMMAND ./gflags-example --version)
add_test(NAME fetching_environment_variable COMMAND ./gflags-example --fromenv myInt32)
add_test(NAME trying_environment_variable COMMAND ./gflags-example --tryfromenv myInt32)
add_test(NAME using_flag_file COMMAND ./gflags-example --flagfile ./flagfile.txt)

set_tests_properties(fetching_environment_variable PROPERTIES ENVIRONMENT "FLAGS_myInt32=128")
set_tests_properties(trying_environment_variable PROPERTIES ENVIRONMENT "FLAGS_myInt32=256")

enable_testing()

