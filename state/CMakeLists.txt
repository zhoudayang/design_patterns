cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11 -g)

add_executable(test_state test_state.cc state.cc)
