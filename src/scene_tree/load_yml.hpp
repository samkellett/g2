#pragma once

#include <yaml-cpp/yaml.h>

namespace g2 {
namespace scene_tree {

YAML::Node load_yml(std::string config)
{
  return YAML::LoadFile(std::move(config));
}

} // namespace scene_tree
} // namespace g2

