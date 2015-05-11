#pragma once

#include <yaml-cpp/yaml.h>

namespace g2 {
namespace scene_tree {

struct load_yml
{
  YAML::Node operator()(std::string config) const
  {
    return YAML::LoadFile(std::move(config));
  }
};

} // namespace scene_tree
} // namespace g2

