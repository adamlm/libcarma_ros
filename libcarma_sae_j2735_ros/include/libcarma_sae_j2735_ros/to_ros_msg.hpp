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

#ifndef LIBCARMA_SAE_J2735_ROS__TO_ROS_MSG_HPP_
#define LIBCARMA_SAE_J2735_ROS__TO_ROS_MSG_HPP_

#include <libcarma/metaprogramming/always_false.hpp>

namespace carma::sae_j2735_ros
{

namespace detail
{

template <typename Msg>
struct do_to_ros_msg
{
  static_assert(
    carma::metaprogramming::always_false_v<do_to_ros_msg<Msg>>,
    "Could not find a class template specialization for specified `Msg` type");
};

}  // namespace detail

template <typename Msg>
inline constexpr auto to_ros_msg = [](auto && arg) -> Msg {
  return detail::do_to_ros_msg<Msg>::_(std::forward<decltype(arg)>(arg));
};

}  // namespace carma::sae_j2735_ros

#endif  // LIBCARMA_SAE_J2735_ROS__TO_ROS_MSG_HPP_
