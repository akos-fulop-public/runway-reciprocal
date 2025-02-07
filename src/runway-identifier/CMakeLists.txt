add_library(runway-identifier STATIC runwayIdentifier.cpp)

target_include_directories(runway-identifier INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
