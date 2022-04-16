cmake_minimum_required(VERSION 3.0.0)
project(DSAstudy)


file(GLOB_RECURSE source_list "src/*.cpp" "src/*.h")

add_executable(DSAstudy ${source_list})