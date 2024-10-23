file(GLOB_RECURSE SRC "../src/*.cpp")
file(GLOB_RECURSE INC "../src/*.hpp")

set(SRC_WITH_NO_MAIN_CPP "")
foreach(src_f ${SRC})
    if(NOT src_f MATCHES "main\.cpp")
        list(APPEND SRC_WITH_NO_MAIN_CPP ${src_f})
    endif()
endforeach()

file(GLOB SRC_FOR_TEST "./*.cpp")

add_executable(tst ${SRC_WITH_NO_MAIN_CPP} ${SRC_FOR_TEST} ${INC}) 

target_link_libraries(tst PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(tc_tst tst)