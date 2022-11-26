
cmake_minimum_required(VERSION 2.8)
project(Project2)
set(CMAKE_CXX_STANDARD 11)

set(Project2_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/bin)
message("exe dir: " ${Project2_OUTPUT_DIR})
## make directory
file( MAKE_DIRECTORY ${Project2_OUTPUT_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${Project2_OUTPUT_DIR})


add_executable(project2  project2.cc)



