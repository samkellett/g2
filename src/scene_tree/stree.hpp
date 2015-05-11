#pragma once

#include <string>

namespace g2 {
namespace scene_tree {

class stree
{
public:
  explicit stree(std::string title);

  stree(const stree &) = delete;
  stree &operator=(const stree &) = delete;

  stree(stree &&) = default;
  stree &operator=(stree &&) = default;

  std::string title() const;

private:
  std::string title_;
};

inline
stree::stree(std::string title)
: title_{std::move(title)}
{
}

inline
std::string stree::title() const
{
  return title_;
}

} // namespace scene_tree
} // namespace g2

