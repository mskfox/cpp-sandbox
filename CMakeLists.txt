cmake_minimum_required(VERSION 3.29)
project(Solutions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "codingame/*.cpp" "leetcode/*.cpp" "neetcode/*.cpp")

foreach(SOURCE ${SOURCES})
	get_filename_component(EXECUTABLE_NAME ${SOURCE} NAME_WE)
	add_executable(${EXECUTABLE_NAME} ${SOURCE})
endforeach()