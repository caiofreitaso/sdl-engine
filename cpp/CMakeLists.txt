cmake_minimum_required(VERSION 3.13)
project(game-engine LANGUAGES CXX VERSION 0.0.1)

option(RUN_TESTS "Build tests" ON)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/obj)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenMP REQUIRED)

if (OPENMP_FOUND)
  set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_definitions(
  -DGL_GLEXT_PROTOTYPES
  -D_REENTRANT
  -msse4.2
  -mavx2
  -march=x86-64
  -malign-double
  -ftree-vectorize
  -ftree-vectorizer-verbose=2
)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories("${PROJECT_SOURCE_DIR}/include")

if(RUN_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()

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
