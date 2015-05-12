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

    auto width(config["width"].as<int>());
    auto height(config["height"].as<int>());

  	return stree(std::move(title), std::move(width), std::move(height));
  }
};

} // namespace scene_tree
} // namespace g2

