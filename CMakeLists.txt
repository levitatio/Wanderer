cmake_minimum_required(VERSION 3.0.0)
project(wanderer VERSION 0.1.0)


#include(CTest)
#enable_testing()
include_directories(src/include)
file(GLOB SOURCES "src/cpps/*.cpp")

add_executable(wanderer "src/main.cpp" ${SOURCES})


#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

target_link_libraries(wanderer SDL2main SDL2 GL SDL2_image)


#set(CMAKE_CXX_STANDARD 14)
#set(SDL2_ROOT_PATH D:/programok/SDL2_windows)
#set(EXECUTABLES "main")
#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)


#find_package(SDL2_all REQUIRED)



