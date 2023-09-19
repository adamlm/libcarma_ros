// Copyright 2023 Adam Morrissett
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>
#include <units.h>

#include <j2735_v2x_msgs/msg/angle.hpp>
#include <libcarma/sae_j2735/angle.hpp>
#include <libcarma_sae_j2735_ros/angle.hpp>

TEST(Angle, ToRosMsg)
{
  using units::literals::operator""_deg;

  const carma::sae_j2735::Angle angle{10_deg};
  const auto result = carma::sae_j2735_ros::to_ros_msg<j2735_v2x_msgs::msg::Angle>(angle);
}
