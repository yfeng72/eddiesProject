cmake_minimum_required(VERSION 3.6)
project(eddiesProject)

set(eddiesProject_VERSION_MAJOR 1)
set(eddiesProject_VERSION_MINOR 0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_FILES main.cpp complex.cpp complex.h fft.cpp fft.h readcsv.cpp readcsv.h threadedFFT.h threadedFFT.cpp)

add_executable(eddiesProject ${SOURCE_FILES})