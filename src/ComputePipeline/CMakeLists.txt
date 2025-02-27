project(ComputePileLine)

# set .cpp to link in lib
set(SOURCES
    src/ComputePipeline.cpp
)


# Link .cpp to be in the lib
add_library(${PROJECT_NAME} ${SOURCES})
add_library(CPL::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        CPL::Actions
        CPL::Loader
)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()
