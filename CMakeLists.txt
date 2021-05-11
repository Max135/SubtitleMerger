cmake_minimum_required(VERSION 3.15)
project(SubtitleMerge)

set(CMAKE_CXX_STANDARD 20)

add_executable(SubtitleMerge main.cpp Block.cpp Block.h TimeStamp.cpp TimeStamp.h SubFile.cpp SubFile.h)