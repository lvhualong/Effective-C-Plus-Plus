
cmake_minimum_required(VERSION 2.8)
project(Project1)
set(CMAKE_CXX_STANDARD 11)

set(Project1_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/bin)
message("exe dir: " ${Project1_OUTPUT_DIR})
## make directory
file( MAKE_DIRECTORY ${Project1_OUTPUT_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${Project1_OUTPUT_DIR})


add_executable(project1  project1.cc)



