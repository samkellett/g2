#pragma once

#include "runtime/system.hpp"

namespace g2 {
namespace runtime {

struct make_system
{
  make_system() = default;

  system operator()(scene_tree::stree tree)
  {
    return system(std::move(tree));
  }
};

} // namespace runtime
} // namespace g2

