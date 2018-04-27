cmake_minimum_required(VERSION 2.6)
project(bdd_test)

set (CMAKE_CXX_STANDARD 11)

link_directories(usr/local/lib/)

include_directories(usr/local/include/)

add_executable(bdd_test main.cpp)

target_link_libraries(bdd_test bdd)
install(TARGETS bdd_test RUNTIME DESTINATION bin)
