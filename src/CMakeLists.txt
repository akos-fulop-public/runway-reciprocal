add_subdirectory(runway-identifier)

add_executable(app main.cpp)
target_link_libraries(app PRIVATE runway-identifier)
