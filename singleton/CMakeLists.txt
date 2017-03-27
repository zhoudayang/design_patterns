add_definitions(-std=c++11)

link_libraries(pthread)

add_executable(test_singleton1 test_singleton1.cc)
add_executable(test_singleton2 test_singleton2.cc)
