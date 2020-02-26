cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_STANDARD 11)

message(STATUS "Building log library...")

ADD_LIBRARY(log STATIC 
	src/log.c)
