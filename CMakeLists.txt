cmake_minimum_required(VERSION 3.0.2)

# 关于project CMakeLists.txt命名关系：https://www.jianshu.com/p/cdd6e56c2422
project(bf_slam)
message (STATUS "top CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")

add_compile_options(-std=c++14)

set(CMAKE_BUILD_TYPE Release)

# default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING
        "Chose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." 
        FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if(CMAKE_BUILD_TYPE MATCHES Release)
    message(STATUS CMAKE_BUILD_TYPE ": ${CMAKE_BUILD_TYPE}")
    add_compile_options(-O3)
else( CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS CMAKE_BUILD_TYPE ": ${CMAKE_BUILD_TYPE}")
    add_compile_options(-g)
    add_compile_options(-O3)
endif(CMAKE_BUILD_TYPE MATCHES Release)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV Library Status: ")
message(STATUS "     version: ${OpenCV_VERSION}")
message(STATUS "     libraries: ${OpenCV_LIBS}")
message(STATUS "     include path: ${OpenCV_INCLUDE_DIRS}")

find_package(Eigen3 REQUIRED)
message(STATUS "Eigen3: ")
message(STATUS "      include path: ${EIGEN3_INCLUDE_DIR}")

find_package(Boost COMPONENTS program_options)
# 把该路径添加到第三方库搜索路径中，方便使用相对路径，在TARGET_LINK_LIBRARIES的，仅给出动态链接库即可
link_directories(${Boost_LIBRARY_DIRS})

# find yaml cpp lib
find_library( YAML_CPP_LIBRARIES yaml-cpp)
if(NOT YAML_CPP_LIBRARIES)
    # If yaml-cpp not found in the system, try finding it as a user CMake-generated project
    find_package(yaml-cpp REQUIRED)
    include_directories(${YAML_CPP_INCLUDE_DIRS})
endif(NOT YAML_CPP_LIBRARIES)


# 包含锁依赖头文件项的路径
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
    ${Boost_LIBRARY_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# add_subdirectory (source_dir [binary_dir] [EXCLUDE_FROM_ALL])
# 添加一个子目录并构建该子目录,该参数指定一个子目录，子目录下应该包含CMakeLists.txt文件和代码文件,
# 子目录可以是相对路径也可以是绝对路径，如果是相对路径，则是相对当前目录的一个相对路径。
# 说明链接： https://blog.51cto.com/u_15127578/4222165
add_subdirectory(test)

