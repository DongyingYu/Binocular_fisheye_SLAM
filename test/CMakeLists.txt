cmake_minimum_required(VERSION 3.0.2)
project(test)
message (STATUS "sub PROJECT_NAME: ${PROJECT_NAME}")


add_executable(test_readimage test_readimage.cc
    ../src/utils.cc    
)
target_link_libraries(test_readimage
  ${OpenCV_LIBS}
)
