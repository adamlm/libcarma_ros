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

# Install CMake dependency management script
# The get_cpm.cmake script must be included before CPMAddPackage(...) calls
set(CPM_DOWNLOAD_VERSION 0.38.2)
include(get_cpm)

# Tell CPM to search for locally-installed packages before using the source
set(CPM_USE_LOCAL_PACKAGES TRUE)

CPMAddPackage(NAME units
  GITHUB_REPOSITORY nholthaus/units
  GIT_TAG v2.3.3
  SYSTEM TRUE
  EXCLUDE_FROM_ALL TRUE
  OPTIONS
    "BUILD_TESTS OFF"
    "BUILD_DOCS OFF"
)

CPMAddPackage(NAME libcarma
  GITHUB_REPOSITORY adamlm/libcarma
  GIT_TAG main
  SYSTEM TRUE
  EXCLUDE_FROM_ALL TRUE
  OPTIONS
    "libcarma_BUILD_LIBRARIES FALSE"
    "libcarma_BUILD_TESTS FALSE"
    "libcarma_BUILD_INSTALL TRUE"
    "libcarma_BUILD_DOCS FALSE"
    "libcarma_BUILD_PACKAGING FALSE"
    "libcarma_sae_j2735_BUILD_LIBRARY TRUE"
)

find_package(ament_cmake REQUIRED)
find_package(j2735_v2x_msgs REQUIRED)
