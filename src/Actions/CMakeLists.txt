project(Actions)

add_library(${PROJECT_NAME} STATIC)
add_library(CPL::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        src/Actions_Factory.cpp
        src/Actions.cpp
        src/Image_Actions.cpp
        src/Decompress_Actions.cpp
        src/JSON_Actions.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()
