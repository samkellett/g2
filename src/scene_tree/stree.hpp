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

bool operator==(const stree &lhs, const stree &rhs);
bool operator!=(const stree &lhs, const stree &rhs);

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

inline
bool operator==(const stree &lhs, const stree &rhs)
{
  return lhs.title() == rhs.title();
}

inline
bool operator!=(const stree &lhs, const stree &rhs)
{
  return ! (lhs == rhs);
}

} // namespace scene_tree
} // namespace g2

