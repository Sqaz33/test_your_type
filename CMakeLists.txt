cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(cmake/addres_sanitizer.cmake)

project(testUrType VERSION 0.0.1 LANGUAGES CXX)

find_package(GTest CONFIG REQUIRED)

#############################################
# main executable
#############################################
file(GLOB_RECURSE SRC "src/*.cpp")
file(GLOB_RECURSE INC "src/*.hpp")

enable_testing()
add_subdirectory(tests)

add_executable(main ${SRC} ${INC})


#############################################
enable_address_sanitizer(main)
enable_address_sanitizer(tst)




