# ##################################################################################################
# CMake general setup
# ##################################################################################################
cmake_minimum_required(VERSION 3.10)

project(ComputePipeLine LANGUAGES CXX )
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 20)

# ##################################################################################################
# User-configurable options
# ##################################################################################################

option(WITH_TESTS "Build Unit tests" OFF)
option(WITH_DOCS "Create Documentation generation target" OFF)

set(ENABLE_TESTS OFF)
if(WITH_TESTS OR WITH_COVERAGE OR WITH_MEMCHECK)
    set(ENABLE_TESTS ON)
endif()

include(EnableVersioning)
set_version(${PROJECT_NAME} 0.1.0 dev)

if(NOT WITH_DOCS STREQUAL "OFF")
    add_subdirectory(doc)
else()
    add_subdirectory(src)

    if(ENABLE_TESTS)
        # enable_testing()
        add_subdirectory(tests)
    endif()
endif()

# ##################################################################################################
# Messages
# ##################################################################################################
message(STATUS "WITH_TESTS     = " ${WITH_TESTS})
message(STATUS "WITH_DOCS      = " ${WITH_DOCS})
