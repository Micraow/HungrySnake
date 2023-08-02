cmake_minimum_required(VERSION 3.7)

# 指定项目名称
project(HungrySnake)

# 为当前路径以及子目录的源文件加入由-D预编译定义
# add_definitions(-DFOO -DDEBUG ...)

# 设置C++编译参数(CMAKE_CXX_FLAGS是全局变量)
# set(CMAKE_CXX_FLAGS "-Wall std=c++11 -Wextra -fPIC -g")

# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定为C++11 版本
set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD 14)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Wno-error)
endif()

# 设置变量
#set(ROOT_DIR /home/micraow/Documents/HungrySnake)

# 头文件查找目录
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/third_party
)
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib)

# 库文件查找目录
link_directories(${PROJECT_SOURCE_DIR}/lib)

# sub_dir指定包含CMakeLists.txt和源码文件的子目录位置
# binary_dir是输出路径， 一般可以不指定
# add_subdirecroty(sub_dir [binary_dir])

# 把src目录下所有源文件写入变量DIR_SRCS
# aux_source_directory(./src DIR_SRCS)

# 以DIR_SRCS为源文件生成目标文件a.out
add_executable(main ./src/main.cpp)
add_library(snake SHARED ./src/snake.cpp)
add_library(render SHARED ./src/render.cpp)
# set_target_properties(main PROPERTIES INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/build/include)
target_link_libraries(render ncurses)
# 创建库文件
# add_library(<name> [STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL] source1 source2 ... sourceN)
# 目标文件链接的库
target_link_libraries(main render snake)
