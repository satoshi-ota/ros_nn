cmake_minimum_required(VERSION 2.8.3)
project(ros_nn)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  sensor_msgs
  tf
  tf2
  tf2_ros
)

set(Caffe2_DIR "$ENV{HOME}/pytorch/torch/share/cmake/Caffe2")
set(Torch_DIR "$ENV{HOME}/pytorch/torch/share/cmake/Torch")
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

if (NOT Torch_FOUND)
    message(FATAL_ERROR "libtorch not found, wavehands_stop will not built.")
else ()
    message(STATUS "++++ found libtorch ")
endif ()

catkin_package(
#  INCLUDE_DIRS include
 LIBRARIES ros_nn
 CATKIN_DEPENDS geometry_msgs nav_msgs roscpp sensor_msgs tf tf2 tf2_ros
 DEPENDS
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(ros_nn src/pytorch_test.cpp)
target_link_libraries(ros_nn ${catkin_LIBRARIES} ${TORCH_LIBRARIES})
set_property(TARGET ros_nn PROPERTY CXX_STANDARD 14)

add_executable(pytorch_frontend_tuto src/pytorch_frontend_tuto.cpp)
target_link_libraries(pytorch_frontend_tuto ${catkin_LIBRARIES} ${TORCH_LIBRARIES})
set_property(TARGET pytorch_frontend_tuto PROPERTY CXX_STANDARD 14)
