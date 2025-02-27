project(Loader)

add_library(${PROJECT_NAME} STATIC)
add_library(CPL::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        src/loader.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include)

set (PROJECT_PACKAGE_NAME ${PROJECT_NAME})
set (
    PROJECT_DEPS
    CPL::Actions
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_DEPS}
)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()
