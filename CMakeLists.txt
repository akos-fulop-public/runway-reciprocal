cmake_minimum_required(VERSION 3.0.0)

project(jumpstart
	VERSION 0.1.0
	HOMEPAGE_URL https://github.com/akos-fulop-public/jumpstart
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_subdirectory(src)
option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
	include(CTest)
	add_subdirectory(test)
endif()
