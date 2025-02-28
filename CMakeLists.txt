# ##################################################################################################
# CMake general setup
# ##################################################################################################
cmake_minimum_required(VERSION 3.16)

project(ComputePipeLine LANGUAGES CXX )
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ##################################################################################################
# User-configurable options
# ##################################################################################################

option(WITH_TESTS "Build Unit tests" OFF)
option(WITH_DOCS "Create Documentation generation target" OFF)

include(EnableDoxygen)
include(EnableTesting)
include(EnableVersioning)

set_version(${PROJECT_NAME} 0.1.0 dev)

set(ENABLE_TESTS OFF)
if(WITH_TESTS OR WITH_COVERAGE OR WITH_MEMCHECK)
    set(ENABLE_TESTS ON)
    enable_testing()
    set_up_gtesting()
endif()


if(NOT WITH_DOCS STREQUAL "OFF")
    set_up_doxygen()
else()
    add_subdirectory(src)

    if(ENABLE_TESTS)
        add_subdirectory(tests)
    endif()
endif()

# ##################################################################################################
# Messages
# ##################################################################################################
message(STATUS "WITH_TESTS     = " ${WITH_TESTS})
message(STATUS "WITH_DOCS      = " ${WITH_DOCS})
