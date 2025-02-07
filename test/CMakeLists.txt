find_package(GTest REQUIRED)

add_executable(runway-identifier-test runwayIdentifierTest.cpp)

target_link_libraries(runway-identifier-test
	PRIVATE GTest::gtest_main
	PRIVATE runway-identifier
)

include(GoogleTest)
gtest_discover_tests(runway-identifier-test)
