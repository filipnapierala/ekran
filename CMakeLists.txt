cmake_minimum_required (VERSION 3.5)
project (operator_HMI)

find_package (OpenCV 3 REQUIRED)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_Release "-O3")

add_executable (operator_HMI inc/GUI.h inc/Screen.h inc/Element.h inc/Button.h inc/Video.h inc/TrackBar.h inc/Image.h inc/Touch.h inc/Utils.h inc/ConfigReader.h src/GUI.cpp src/Screen.cpp src/Element.cpp src/Button.cpp src/Video.cpp src/TrackBar.cpp src/Image.cpp src/Touch.cpp src/Utils.cpp src/ConfigReader.cpp main.cpp)

target_link_libraries (operator_HMI ${OpenCV_LIBS} pthread)
