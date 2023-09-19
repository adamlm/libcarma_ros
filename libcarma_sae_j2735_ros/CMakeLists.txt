# Copyright 2023 Adam Morrissett
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.21)
project(libcarma_sae_j2735_ros)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(options.cmake)
include(dependencies.cmake)

# CARMA targets C++17 and C17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ${libcarma_sae_j2735_ros_EXPORT_COMPILE_COMMANDS})

# This prevents colcon from trying to build CMake build artifacts when the
# project is incorporated into a ROS 2 workspace.
file(TOUCH ${PROJECT_BINARY_DIR}/COLCON_IGNORE)

# ament_cmake_auto does not support INTERFACE libraries, so we have to do
# things manually.
add_library(libcarma_sae_j2735_ros INTERFACE)

target_include_directories(libcarma_sae_j2735_ros
  INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

ament_target_dependencies(libcarma_sae_j2735_ros
  INTERFACE
    j2735_v2x_msgs
)

target_link_libraries(libcarma_sae_j2735_ros
  INTERFACE
    libcarma::metaprogramming
    libcarma::sae_j2735
)

if(libcarma_sae_j2735_ros_BUILD_TESTS)
  enable_testing()

  add_executable(libcarma_sae_j2735_ros_tests
    test/test_angle.cpp
  )

  ament_target_dependencies(libcarma_sae_j2735_ros_tests
    j2735_v2x_msgs
  )

  # ament_target_dependencies doesn't support PRIVATE, so can't link testing
  # dependencies using the PRIVATE scope.
  target_link_libraries(libcarma_sae_j2735_ros_tests
    GTest::gtest_main
    libcarma_sae_j2735_ros
  )

  include(GoogleTest)
  gtest_discover_tests(libcarma_sae_j2735_ros_tests)
endif()

ament_auto_package()
