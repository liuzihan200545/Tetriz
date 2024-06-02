cmake_minimum_required(VERSION 3.20)

project(tetriz)

set(CXX_STANDARD 20)

aux_source_directory(. src)

#查找依赖库
find_package(Threads REQUIRED)
 
add_executable(${CMAKE_PROJECT_NAME} main.cpp ${src})
#这里一定要加上add_executable才能在下面引入依赖库文件！
 
#引入依赖库
target_link_libraries(${CMAKE_PROJECT_NAME} Threads::Threads)


