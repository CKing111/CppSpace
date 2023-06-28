cmake_minimum_required(VERSION 3.10)  # 设定最低版本

project(pp3-StudentManager VERSION 1.0.0 LANGUAGES CXX)  
#         项目名，         版本        语言CPP

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # 标准语法， CMake 将会强制使用指定的 C++ 标准进行编译，即使编译器默认使用的标准低于所需的标准。
# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

# 添加源代码文件
add_executable(pp3-StudentManager
${PROJECT_SOURCE_DIR}/src/SManager.cpp
${PROJECT_SOURCE_DIR}/src/Student.cpp
${PROJECT_SOURCE_DIR}/src/main.cpp
)

# 添加头文件目录
target_include_directories(pp3-StudentManager PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 添加链接库
target_link_libraries(pp3-StudentManager PRIVATE ${CONAN_LIBS})

# 设置可执行文件的输出路径
set_target_properties(pp3-StudentManager PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})