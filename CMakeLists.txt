cmake_minimum_required(VERSION 3.20.0)
project(Cmake_proj)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (EXECUTABLE_OUTPUT_PATH ../${CMAKE_BUILD_TYPE})

include(CTest)
enable_testing()

# test-lib
add_subdirectory(say-hello)

# entry point
add_subdirectory(MyProgram)

# SFML
add_subdirectory(SFML)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    sfml‑system
    sfml‑window
    sfml‑network
    sfml‑graphics
    sfml‑audio
    sfml‑main
)

target_include_directories(${PROJECT_NAME} PUBLIC
    SFML/include
)
