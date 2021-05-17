cmake_minimum_required(VERSION 3.0.0)
project(CMake_proj)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (EXECUTABLE_OUTPUT_PATH ../${CMAKE_BUILD_TYPE})

include(CTest)
enable_testing()

LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/../SFML)
TARGET_LINK_LIBRARIES(GLBall mylib)

add_subdirectory(say-hello)
add_subdirectory(MyProgram)