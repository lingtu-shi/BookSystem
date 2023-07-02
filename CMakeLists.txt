# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("BookSystem")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

SET(INCLUDE_PATH
	./include
)
include_directories(${INCLUDE_PATH})       

file(GLOB SOURCE_CPP
	*.cpp
	src/*.cpp
)
add_executable (${CMAKE_PROJECT_NAME}
	${SOURCE_CPP}
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()