project(${PROJECT_PACKAGE_NAME}_Tests)

add_executable(${PROJECT_NAME} test_loader.cpp)

if(GTest_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC GTest::GTest GTest::gtest_main CPL::${PROJECT_PACKAGE_NAME} ${PROJECT_DEPS})
else()
    target_link_libraries(${PROJECT_NAME} PUBLIC gtest gtest_main CPL::${PROJECT_PACKAGE_NAME} ${PROJECT_DEPS})
endif()

add_test(NAME ${PROJECT_PACKAGE_NAME}Tests COMMAND ${PROJECT_NAME})
