
cmake_minimum_required(VERSION 2.8)
project(Project3)
set(CMAKE_CXX_STANDARD 11)

set(Project3_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/bin)
message("exe dir: " ${Project3_OUTPUT_DIR})
## make directory
file( MAKE_DIRECTORY ${Project3_OUTPUT_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${Project3_OUTPUT_DIR})


add_executable(project3  project3.cc)

add_executable(key_gen  key_gen.cc)

add_executable(hello_world_exe  hello_world_exe.cc)



