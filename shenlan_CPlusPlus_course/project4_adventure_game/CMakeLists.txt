
cmake_minimum_required(VERSION 2.8)
project(Project4)
set(CMAKE_CXX_STANDARD 11)

set(Project4_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/bin)
message("exe dir: " ${Project4_OUTPUT_DIR})
## make directory
file( MAKE_DIRECTORY ${Project4_OUTPUT_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${Project4_OUTPUT_DIR})


add_executable(project4  project4.cc)



