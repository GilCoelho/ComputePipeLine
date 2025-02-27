#[=======================================================================[.rst:
.. cmake:command:: set_up_gtesting

  Function check and install Google Test.

  .. code-block:: cmake

    set_up_gtesting()
#]=======================================================================]
function(set_up_gtesting)
    find_package(GTest QUIET)

    include(FetchContent)

    if(NOT GTest_FOUND)
        message(STATUS "Downloading Google Test")

        # Add Google Test via FetchContent if not found
        FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG        release-1.12.1
        )

        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)

        # Install GoogleTest so find_package can find it later
        message(STATUS "Installing Google Test")
        install(TARGETS gtest gtest_main
            DESTINATION lib)
        install(DIRECTORY ${gtest_SOURCE_DIR}/include
            DESTINATION include)

        #find_package(GTest REQUIRED)
    endif()
endfunction()
