CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
	 
PROJECT(Memory)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
 
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
 
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
 
add_subdirectory(Lesson1)
add_subdirectory(Lesson2)
add_subdirectory(Lesson3)
add_subdirectory(Lesson4)
