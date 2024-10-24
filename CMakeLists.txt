cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(cmake/addres_sanitizer.cmake)

project(testUrType VERSION 0.0.1 LANGUAGES CXX)

# packages
find_package(GTest CONFIG REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#############################################
# main executable
#############################################
file(GLOB_RECURSE SRC "src/*.cpp")
file(GLOB_RECURSE INC "src/*.hpp")
file(GLOB_RECURSE UI "src/*.ui")

enable_testing()
add_subdirectory(tests)

add_executable(main ${SRC} ${INC} ${UI})

target_link_libraries(main PRIVATE Qt5::Core Qt5::Widgets)

#############################################
enable_address_sanitizer(main)





