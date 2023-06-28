cmake_minimum_required(VERSION 3.10)

project(pp2-ZooManagementSystem VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(pp2-ZooManagementSystem
${PROJECT_SOURCE_DIR}/main.cpp
${PROJECT_SOURCE_DIR}/animal.cpp
${PROJECT_SOURCE_DIR}/lion.cpp
${PROJECT_SOURCE_DIR}/elephant.cpp
)
# 设置可执行文件的输出路径
set_target_properties(pp2-ZooManagementSystem PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

target_include_directories(pp2-ZooManagementSystem
  PRIVATE  # 表示这个目录只会影响这个目标本身，而不会影响依赖这个目标的其他目标。
    ${CMAKE_CURRENT_SOURCE_DIR}
)
# 这个命令指定了目标（即可执行文件）的包含目录。在这里，它将当前源代码目录（
# (${CMAKE_CURRENT_SOURCE_DIR}(表示当前正在处理的CMakeLists.txt文件所在的目录的绝对路径。))
# ）添加到目标的包含目录中。
# 这样做可以确保编译器可以找到所需的头文件。