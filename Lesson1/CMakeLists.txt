CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
	 
PROJECT(Lesson1)

set(CMAKE_CXX_FLAGS "-std=c++14")

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
 
set(Lesson1_SRCS
${PROJECT_SOURCE_DIR}/categorizer.cpp
)
 
include_directories("${PROJECT_BINARY_DIR}")
add_executable(${PROJECT_NAME} ${Lesson1_SRCS})
include_directories("${PROJECT_INCLUDE_DIR}")

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/splash.pgm ${CMAKE_CURRENT_BINARY_DIR}/splash.pgm
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/splash.png ${CMAKE_CURRENT_BINARY_DIR}/splash.png)
