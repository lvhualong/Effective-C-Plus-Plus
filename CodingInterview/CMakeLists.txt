
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

set( CodingInterview_OUTPUT_DIR ${PROJECT_OUTPUT_DIR}/bin/codingInterview)

## make directory
##file( MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR})
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/bin)
#file( MAKE_DIRECTORY ${LeeCode_OUTPUT_DIR}/lib)
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CodingInterview_OUTPUT_DIR})

##
add_executable(03_duplicationInArray 03_duplicationInArray/03_duplicationInArray.cpp)
add_executable(04_findInPartiallySortedMatrix 04_findInPartiallySortedMatrix/04_findInPartiallySortedMatrix.cpp)

