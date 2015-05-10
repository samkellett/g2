#pragma once

#include <yaml-cpp/yaml.h>

namespace g2 {
namespace config {

struct load
{
  YAML::Node operator()(std::string config) const
  {
    return YAML::LoadFile(std::move(config));
  }
};

} // namespace config
} // namespace g2
