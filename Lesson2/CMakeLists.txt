CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
	 
PROJECT(Lesson2)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(Lesson2_SRCS
${PROJECT_SOURCE_DIR}/main.cpp 
)
 
include_directories("${PROJECT_BINARY_DIR}")
add_executable(${PROJECT_NAME} ${Lesson2_SRCS})
include_directories("${PROJECT_INCLUDE_DIR}")