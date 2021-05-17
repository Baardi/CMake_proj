project(Cmake-proj)
cmake_minimum_required(VERSION 3.17.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(BUILD_SHARED_LIBS ON)

add_executable(${PROJECT_NAME} main.cpp)

#SFML
add_subdirectory(SFML)
target_link_libraries(${PROJECT_NAME} PUBLIC 
    sfml-system
    sfml-window
    sfml-network
    sfml-graphics
    sfml-audio
    sfml-main
)
