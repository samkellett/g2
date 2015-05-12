#pragma once

#include <string>

namespace g2 {
namespace scene_tree {

class stree
{
public:
  stree(std::string title, int width, int height);

  stree(const stree &) = delete;
  stree &operator=(const stree &) = delete;

  stree(stree &&) = default;
  stree &operator=(stree &&) = default;

  const std::string &title() const &;
  std::string &title() &;

  int width() const &;

  int height() const &;

private:
  std::string title_;

  int width_;
  int height_;
};

bool operator==(const stree &lhs, const stree &rhs);
bool operator!=(const stree &lhs, const stree &rhs);

inline
stree::stree(std::string title, int width, int height)
: title_{std::move(title)},
  width_{std::move(width)},
  height_{std::move(height)}
{
}

inline
const std::string &stree::title() const &
{
  return title_;
}

inline
std::string &stree::title() &
{
  return title_;
}

int stree::width() const &
{
  return width_;
}

int stree::height() const &
{
  return height_;
}

inline
bool operator==(const stree &lhs, const stree &rhs)
{
  return lhs.title() == rhs.title()
    && lhs.width() == rhs.width()
    && lhs.height() == rhs.height();
}

inline
bool operator!=(const stree &lhs, const stree &rhs)
{
  return ! (lhs == rhs);
}

} // namespace scene_tree
} // namespace g2

