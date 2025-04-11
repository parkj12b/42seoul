cmake_minimum_required(VERSION 3.10)
project(project-name)

set(CMAKE_C_STANDARD 11)

enable_testing()

find_package(Criterion REQUIRED)

include_directories(${CRITERION_INCLUDE_DIRS})

file(GLOB TEST_SOURCES tests/*.c)

add_executable(run_tests ${TEST_SOURCES})
target_link_libraries(run_tests ${CRITERION_LIBRARIES})

add_test(NAME run_tests COMMAND run_tests)