
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( Programming_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/programming)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${Programming_OUTPUT_DIR})


## include_directories(${PROJECT_SOURCE_DIR}/LeeCode/001_twoSum)
add_executable(sqrt_exe sqrt.cpp)