cmake_minimum_required(VERSION 3.13)
project(game-engine LANGUAGES CXX VERSION 0.0.1)

option(RUN_TESTS "Build tests" ON)
if(RUN_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/obj)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenMP REQUIRED)

add_definitions(-DGL_GLEXT_PROTOTYPES -D_REENTRANT)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB_RECURSE gameengine_SRC "${PROJECT_SOURCE_DIR}/src/**.cc")

add_executable(game-engine ${gameengine_SRC})
target_link_libraries(game-engine
  m
  SDL2
  stdc++
  GL
  GLU
  glut
)
