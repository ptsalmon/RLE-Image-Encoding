cmake_minimum_required(VERSION 3.20)
project(Project3)

set(CMAKE_CXX_STANDARD 11)

add_executable(image-processor src/image-processor.cpp src/Image.cpp src/Image.h)