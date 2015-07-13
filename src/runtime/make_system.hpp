#pragma once

#include "runtime/system.hpp"

namespace g2 {
namespace runtime {

system make_system(scene_tree::stree tree)
{
  return system(std::move(tree), nullptr);
}

} // namespace runtime
} // namespace g2

