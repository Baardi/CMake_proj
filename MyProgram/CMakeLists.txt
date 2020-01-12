add_executable(Cmake_proj main.cpp)

target_link_libraries(Cmake_proj PRIVATE say-hello)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
