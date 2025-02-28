#[=======================================================================[.rst:
.. cmake:command:: set_up_doxygen

  Function check and install Doxygen.

  .. code-block:: cmake

    set_up_doxygen()
#]=======================================================================]
function(set_up_doxygen)
    include(FetchContent)

    FetchContent_Declare(
        doxygen
        GIT_REPOSITORY https://github.com/doxygen/doxygen.git
        GIT_TAG        Release_1_13_2
    )

    FetchContent_MakeAvailable(doxygen)

    find_package(Doxygen REQUIRED)

    if(DOXYGEN_FOUND)
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

        add_custom_target(doc_doxygen
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
        )

        message(STATUS "Doxygen found, documentation target added.")
    else()
        message(WARNING "Doxygen not found, documentation target will not be available.")
    endif()
endfunction()