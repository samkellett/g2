#pragma once

#include "scene_tree/stree.hpp"

namespace g2 {
namespace runtime {

class system
{
public:
  explicit system(scene_tree::stree);

  system(const system &) = delete;
  system &operator=(const system &) = delete;

  system(system &&) = default;
  system &operator=(system &&) = default;

  const scene_tree::stree &tree() const;

private:
  scene_tree::stree tree_;
};

bool operator==(const system &lhs, const system &rhs);
bool operator!=(const system &lhs, const system &rhs);

inline
system::system(scene_tree::stree tree)
: tree_(std::move(tree))
{
}

inline
const scene_tree::stree &system::tree() const
{
  return tree_;
}

inline
bool operator==(const system &lhs, const system &rhs)
{
  return lhs.tree() == rhs.tree();
}

inline
bool operator!=(const system &lhs, const system &rhs)
{
  return ! (lhs == rhs);
}

} // namespace runtime
} // namespace g2

