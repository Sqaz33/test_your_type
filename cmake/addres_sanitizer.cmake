function(enable_address_sanitizer target)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        # GCC или Clang: включаем AddressSanitizer
        target_compile_options(${target} PRIVATE -fsanitize=address -fno-omit-frame-pointer)
        target_link_options(${target} PRIVATE -fsanitize=address)
    elseif (MSVC)
        # Проверка версии MSVC
        if (MSVC_VERSION GREATER_EQUAL 1927)  # MSVC 2019 16.7 или новее
            message(STATUS "Enabling AddressSanitizer for MSVC")
            target_compile_options(${target} PRIVATE /fsanitize=address /Zi)
            target_link_options(${target} PRIVATE /fsanitize=address /Zi)
        else()
            message(WARNING "AddressSanitizer is not supported in this version of MSVC. Please use MSVC 2019 16.7 or later.")
        endif()
    else()
        message(WARNING "Unknown compiler: AddressSanitizer may not be supported")
    endif()
endfunction()