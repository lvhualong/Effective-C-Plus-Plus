cmake_minimum_required(VERSION 2.8)
project(Boost_operate)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

find_package(Boost)
if(NOT Boost_FOUND)
    message("Not found Boost")
endif()
include_directories(${Boost_INCLUDE_DIRS})



add_executable(01_create_thread  src/01_create_thread.cpp)
target_link_libraries(
    01_create_thread
    ${Boost_LIBRARIES}
)