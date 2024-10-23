cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(cmake/addres_sanitizer.cmake)

project(testUrType VERSION 0.0.1 LANGUAGES CXX)

find_package(GTest CONFIG REQUIRED)

#############################################
# executable
#############################################
file(GLOB_RECURSE SRC "src/*.cpp")
file(GLOB_RECURSE INC "src/*.hpp")

enable_testing()

add_executable(main ${SRC} ${INC})

#############################################
# tests
#############################################
set(SRC_WITH_NO_MAIN_CPP "")
foreach(src_f ${SRC})
    if(NOT src_f MATCHES "main\.cpp")
        list(APPEND SRC_WITH_NO_MAIN_CPP ${src_f})
    endif()
endforeach()

message(${SRC_WITH_NO_MAIN_CPP})

file(GLOB SRC_FOR_TEST "tests/*.cpp")

add_executable(tst ${SRC_WITH_NO_MAIN_CPP} ${SRC_FOR_TEST} ${INC}) 
target_link_libraries(tst PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
add_test(tc_tst tst)

#############################################
enable_address_sanitizer(main)
enable_address_sanitizer(tst)


