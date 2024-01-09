cmake_minimum_required(VERSION 3.10)

project(cpp_projects)

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Include SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS})

# Add your source files
add_executable(mandel mandelbrot.cpp)

# Link against SDL2 library
target_link_libraries(mandel ${SDL2_LIBRARIES})
