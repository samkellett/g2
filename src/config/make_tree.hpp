#pragma once

namespace g2 {
namespace config {

struct make_tree
{
  int operator()(YAML::Node) const
  {
    return 1;
  }
};

} // namespace config
} // namespace g2
