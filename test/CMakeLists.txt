find_package(GTest REQUIRED)

add_executable(example-test exampleTest.cpp)

target_link_libraries(example-test
	PRIVATE GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(example-test)
