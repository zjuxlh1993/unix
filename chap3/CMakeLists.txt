# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE "Debug")

# 项目名称
project(PTONLOOSE)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_ROOT_SRCS变量
aux_source_directory(. DIR_ROOT_SRCS)

# 指定生成目标
add_executable(a.out ${DIR_ROOT_SRCS})

# 添加链接库
target_link_libraries(a.out)

