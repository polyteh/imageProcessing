cmake_minimum_required(VERSION 2.8)
SET("OpenCV_DIR" "D:/Education/C++/opencv/opencv_3.4.3-winrar/build")
set (CMAKE_CXX_STANDARD 11)
project(image)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(SRCS 	myImageProcessing.h
			myImageProcessing.cpp
	)
add_executable(image image.cpp ${SRCS})
target_link_libraries(image ${OpenCV_LIBS} )