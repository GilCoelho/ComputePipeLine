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

#[=======================================================================[.rst:
.. cmake:command:: add_unit_test

  Function Create and build unitary tests.

  .. code-block:: cmake

    add_unit_test(
        _proj_name <name>
        _sources <sources>
        _deps <dependencies>
    )
#]=======================================================================]
function(add_unit_test _proj_name _sources _deps)
    project(${_proj_name}_Tests)

    message(STATUS ${_proj_name})
    message(STATUS ${PROJECT_NAME})

    add_executable(${PROJECT_NAME} ${_sources})

    if(GTest_FOUND)
        target_link_libraries(${PROJECT_NAME} PUBLIC GTest::GTest GTest::gtest_main CPL::${_proj_name} ${_deps})
    else()
        target_link_libraries(${PROJECT_NAME} PUBLIC gtest gtest_main CPL::${_proj_name} ${_deps})
    endif()

    add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
endfunction()
