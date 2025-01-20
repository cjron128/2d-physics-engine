cmake_minimum_required(VERSION 3.10)
project(2DPhysicsEngine)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Add SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Executable
add_executable(2DPhysicsEngine ${SOURCES})
target_link_libraries(2DPhysicsEngine sfml-system sfml-window sfml-graphics)
