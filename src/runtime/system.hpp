#pragma once

#include "runtime/window.hpp"

#include "scene_tree/stree.hpp"

#include <memory>

namespace g2 {
namespace runtime {

class system
{
public:
  system(scene_tree::stree, g2::runtime::window);

  system(const system &) = delete;
  system &operator=(const system &) = delete;

  system(system &&) = default;
  system &operator=(system &&) = default;

  const scene_tree::stree &tree() const &;

  const g2::runtime::window &window() const &;
  g2::runtime::window &window() &;

private:
  scene_tree::stree tree_;
  g2::runtime::window window_;
};

bool operator==(const system &lhs, const system &rhs);
bool operator!=(const system &lhs, const system &rhs);

inline
system::system(scene_tree::stree tree, g2::runtime::window window)
: tree_{std::move(tree)},
  window_{std::move(window)}
{
}

inline
const scene_tree::stree &system::tree() const &
{
  return tree_;
}

inline
const g2::runtime::window &system::window() const &
{
  return window_;
}

inline
g2::runtime::window &system::window() &
{
  return window_;
}

inline
bool operator==(const system &lhs, const system &rhs)
{
  return lhs.tree() == rhs.tree()
    && lhs.window() == rhs.window();
}

inline
bool operator!=(const system &lhs, const system &rhs)
{
  return ! (lhs == rhs);
}

} // namespace runtime
} // namespace g2

