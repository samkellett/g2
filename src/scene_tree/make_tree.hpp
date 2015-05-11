#pragma once

#include "scene_tree/stree.hpp"

#include <yaml-cpp/yaml.h>

namespace g2 {
namespace scene_tree {

struct make_tree
{
  stree operator()(YAML::Node config) const
  {
    auto title(config["title"].as<std::string>());

	return stree(std::move(title));
  }
};

} // namespace scene_tree
} // namespace g2

