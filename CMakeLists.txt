cmake_minimum_required (VERSION 3.5)
project (operator_HMI)

find_package (OpenCV 3 REQUIRED)
set(CMAKE_CXX_STANDARD 14)

#include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)
#link_directories(${CMAKE_BINARY_DIR}/bin)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable (operator_HMI inc/GUI.h src/GUI.cpp main.cpp)

target_link_libraries (operator_HMI ${OpenCV_LIBS} pthread)
