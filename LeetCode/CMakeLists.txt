
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( LeetCode_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/LeetCode)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${LeetCode_OUTPUT_DIR})


## include_directories(${PROJECT_SOURCE_DIR}/LeetCode/001_twoSum)
add_executable(001_twoSumEXE 001_twoSum/001_twoSum.cpp)
add_executable(104_BinTreeMaxDepth 104_BinTreeMaxDepth/104_binTreeMaxDepth.cpp)
add_executable(334_reverseString 334_reverseString/334_reverseString.cpp)