add_executable(isc_tst IncrementalStringComparer_tests.cpp) 

include(../cmake/addres_sanitizer.cmake)

target_link_libraries(isc_tst PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

enable_address_sanitizer(isc_tst)

add_test(isc_tst tst)