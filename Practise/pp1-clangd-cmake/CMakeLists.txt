cmake_minimum_required(VERSION 3.15.0)  # CMake最低版本要求
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/local/lib/cmake/fmt")

project(pp1-clangd-cmake)        # 工程名

#以下是一些常用的路径相关参数和变量：
# CMAKE_SOURCE_DIR：CMake 源代码目录的路径。
# CMAKE_BINARY_DIR：CMake 构建目录的路径。
# CMAKE_INSTALL_PREFIX：安装目录的路径。
# PROJECT_SOURCE_DIR：当前项目的源代码目录的路径。
# PROJECT_BINARY_DIR：当前项目的构建目录的路径。
# CMAKE_CURRENT_SOURCE_DIR：当前 CMakeLists.txt 文件所在的目录的路径。
# CMAKE_CURRENT_BINARY_DIR：当前 CMakeLists.txt 文件的构建目录的路径。
# CMAKE_MODULE_PATH：CMake 模块文件所在的路径。

set(CMAKE_CXX_STANDARD 20)  # 设置C++标准
set(CMAKE_CXX_EXTENSIONS OFF)   # 不要扩展
# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})


add_executable(pp1-clangd-cmake 
${PROJECT_SOURCE_DIR}/helloword.cpp
${PROJECT_SOURCE_DIR}/src/boo.cpp
)

# 设置可执行文件的输出路径
set_target_properties(pp1-clangd-cmake PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})


        # add_executable：用于定义一个可执行文件目标，并将源代码文件与之关联。
        # ${CMAKE_PROJECT_NAME}：要生成的可执行文件的名称，是一个预定义的变量，表示当前项目的名称。
        #                          它通常用于定义和管理项目中各种构建目标的名称、属性和依赖关系。
find_package(fmt REQUIRED)
        # find_package：用于查找和加载一个或多个已安装的软件包，并提供相应的配置信息和库文件路径等信息。
        #               该命令通常用于定义和管理项目中依赖的外部软件包以及它们的依赖关系。
        # fmt：库
        # REQUIRED： 指示必须找到此库
target_link_directories(pp1-clangd-cmake PRIVATE
    fmt::fmt
)
        # target_link_directories:用于将指定目标的链接器搜索路径添加到给定的目标中。
        #                         该命令通常用于在项目构建过程中引用外部库的动态链接库或静态库。
        #       将 fmt 库的链接器搜索路径添加到 "hello_world" 可执行文件中
target_link_libraries(pp1-clangd-cmake  fmt::fmt)
target_include_directories(pp1-clangd-cmake PRIVATE
    src
)
# 在上述示例中，"target_link_libraries" 命令用于将 "hello_world" 可执行文件链接到 fmt 库。
#"target_link_directories" 命令用于将 fmt 库的链接器搜索路径添加到 "hello_world" 可执行文件中。
#这样，链接器就能够找到 fmt 库的动态链接库或静态库。

# 需要注意的是，"target_link_directories" 命令可能会导致链接器搜索路径冲突或安全问题。
# 因此，建议使用 "find_library" 命令或其他更安全的方式来查找和链接外部库。
# 例如，可以使用 "find_package" 命令来查找并链接外部库，或者使用 "target_include_directories" 命令来添加头文件搜索路径。


# 表示使用 Clang-Tidy 工具对 C++ 代码进行分析，并启用所有检查规则。
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*;--")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)  
# CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 变量设置为 ON，表示在将分析结果输出到文件时，将文件扩展名替换为 .txt。
add_custom_command(OUTPUT tidy.txt      # add_custom_command 命令将在构建目标时运行
                   COMMAND ${CMAKE_CXX_CLANG_TIDY}
                   DEPENDS ${SOURCES}
                   COMMENT "Running Clang-Tidy")
# add_custom_target(tidy_output DEPENDS ./tidy.txt)     # 在构建完成后输出分析结果到文件中