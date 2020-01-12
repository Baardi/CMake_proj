cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/.build/${CMAKE_BUILD_TYPE})
project(Cmake_proj VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(say-hello)
add_subdirectory(MyProgram)