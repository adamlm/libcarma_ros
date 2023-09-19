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

#ifndef LIBCARMA_SAE_J2735_ROS__ANGLE_HPP_
#define LIBCARMA_SAE_J2735_ROS__ANGLE_HPP_

#include <units.h>

#include <j2735_v2x_msgs/msg/angle.hpp>
#include <libcarma/sae_common/data_unavailable.hpp>
#include <libcarma/sae_common/units_extensions.hpp>
#include <libcarma/sae_j2735/angle.hpp>

#include "libcarma_sae_j2735_ros/from_ros_msg.hpp"
#include "libcarma_sae_j2735_ros/to_ros_msg.hpp"

namespace carma::sae_j2735_ros
{

template <>
struct detail::do_to_ros_msg<j2735_v2x_msgs::msg::Angle>
{
  static auto _(const carma::sae_j2735::Angle & angle) noexcept -> j2735_v2x_msgs::msg::Angle
  {
    j2735_v2x_msgs::msg::Angle msg;

    if (angle.is_available()) {
      msg.angle = units::unit_cast<double>(angle.value());
    } else {
      msg.angle = msg.ANGLE_UNAVAILABLE;
    }

    return msg;
  }
};

template <>
struct detail::do_from_ros_msg<carma::sae_j2735::Angle>
{
  static auto _(const j2735_v2x_msgs::msg::Angle & msg) noexcept -> carma::sae_j2735::Angle
  {
    carma::sae_j2735::Angle angle{carma::sae_common::data_unavailable};

    if (msg.angle != msg.ANGLE_UNAVAILABLE) {
      angle = units::angle::eighth_deci_degree_t{static_cast<double>(msg.angle)};
    }

    return angle;
  }
};

}  // namespace carma::sae_j2735_ros

#endif  // LIBCARMA_SAE_J2735_ROS__ANGLE_HPP_
