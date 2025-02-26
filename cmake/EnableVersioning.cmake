#[=======================================================================[.rst:
Versioning
----------

This module provides a function that correctly sets the project version.
It not only supports version in the format Major.Minor.Patch but it also supports an extension,
stating whether it is a release, snapshot, nightly, etc.

It generates a C++ header file (version.h), configured with the provided version and other useful values,
such as build timestamp and git revision hash
#]=======================================================================]

find_package(Git REQUIRED)

#[=======================================================================[.rst:
.. cmake:command:: set_version

  Function that configures the project version.

  .. code-block:: cmake

    set_version(_namespace _version [_tweak])

  ``_namespace`` is the namespace of the project.

  ``_version`` is a string in the format Major.Minor.Patch.

  ``_tweak`` is optional. It is used as a suffix for the version.
#]=======================================================================]
function(set_version _namespace _version)
    STRING(REGEX REPLACE "^([0-9]+)\\.[0-9]+\\.[0-9]+" "\\1" _major "${_version}")
    STRING(REGEX REPLACE "^[0-9]+\\.([0-9])+\\.[0-9]+" "\\1" _minor "${_version}")
    STRING(REGEX REPLACE "^[0-9]+\\.[0-9]+\\.([0-9]+)" "\\1" _patch "${_version}")

    set(${_namespace}_MAJOR_VERSION ${_major} PARENT_SCOPE)
    set(${_namespace}_MINOR_VERSION ${_minor} PARENT_SCOPE)
    set(${_namespace}_PATCH_LEVEL ${_patch} PARENT_SCOPE)

    set (extra_args ${ARGN})
    list(LENGTH extra_args extra_count)

    if (${extra_count} GREATER 0)
        list(GET extra_args 0 _tweak)
        set(${_namespace}_TWEAK ${_tweak} PARENT_SCOPE)
        set(INTERNAL_PROJECT_VERSION ${_major}.${_minor}.${_patch}-${_tweak})
        set(${_namespace}_SOVERSION ${_major}.${_minor}.${_patch}-${_tweak} PARENT_SCOPE)
    else()
        set(INTERNAL_PROJECT_VERSION ${_major}.${_minor}.${_patch} )
        set(${_namespace}_SOVERSION ${_major}.${_minor}.${_patch} PARENT_SCOPE)
    endif()
    set(${_namespace}_VERSION ${INTERNAL_PROJECT_VERSION} PARENT_SCOPE)

    # Configure version file
    set(GEN_CONFIG_FILES_DIR "${CMAKE_BINARY_DIR}/generated")
    string(TIMESTAMP INTERNAL_PROJECT_TIMESTAMP "%Y-%m-%dT%H:%M:%S")

    if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
        execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
                        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
                        OUTPUT_VARIABLE PACKAGE_GIT_VERSION
                        OUTPUT_STRIP_TRAILING_WHITESPACE)

        set(INTERNAL_PROJECT_PACKAGE_GIT_VERSION ${PACKAGE_GIT_VERSION})
    endif()

    string(TOUPPER ${_namespace} INTERNAL_UPPER_PROJECT_NAME)
    string(TOLOWER ${_namespace} INTERNAL_LOWER_PROJECT_NAME)

    configure_file(${PROJECT_SOURCE_DIR}/cmake/version.h.in ${GEN_CONFIG_FILES_DIR}/version/include/version/version.h)

    unset(INTERNAL_UPPER_PROJECT_NAME)
    unset(INTERNAL_LOWER_PROJECT_NAME)
    unset(INTERNAL_PROJECT_PACKAGE_GIT_VERSION)
    unset(INTERNAL_PROJECT_TIMESTAMP)
    unset(INTERNAL_PROJECT_VERSION)
endfunction()