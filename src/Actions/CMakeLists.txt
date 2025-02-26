project(Actions)

add_library(${PROJECT_NAME} STATIC)
add_library(CPL::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        src/Actions.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include)

add_subdirectory(tests)