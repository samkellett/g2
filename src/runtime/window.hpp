#pragma once

#include <GLFW/glfw3.h>

#include <memory>

namespace g2 {
namespace runtime {

class window
{
public:
  window();
  window(std::nullptr_t);
  window(GLFWwindow *window);

  window &operator=(GLFWwindow *window);

  operator GLFWwindow *();
  operator GLFWwindow *const() const;

private:
  struct deleter
  {
    void operator()(GLFWwindow *window) const;
  };

  std::unique_ptr<GLFWwindow, deleter> window_;
};

bool operator==(const window &lhs, const window &rhs);
bool operator!=(const window &lhs, const window &rhs);

bool operator==(GLFWwindow *const lhs, const window &rhs);
bool operator!=(GLFWwindow *const lhs, const window &rhs);

inline
window::window()
: window_(nullptr, deleter())
{
}

inline
window::window(std::nullptr_t)
: window()
{
}

inline
window::window(GLFWwindow *win)
: window_(win, deleter())
{
}

inline
window &window::operator=(GLFWwindow *window)
{
  window_ = std::unique_ptr<GLFWwindow, deleter>(window, deleter());
  return *this;
}

inline
window::operator GLFWwindow *()
{
  return window_.get();
}

inline
window::operator GLFWwindow *const() const
{
  return window_.get();
}

inline
void window::deleter::operator()(GLFWwindow *window) const
{
  glfwDestroyWindow(window);
}

inline
bool operator==(const window &lhs, const window &rhs)
{
  return static_cast<GLFWwindow *const>(lhs) == static_cast<GLFWwindow *const>(rhs);
}

inline
bool operator!=(const window &lhs, const window &rhs)
{
  return ! (lhs == rhs);
}

inline
bool operator==(GLFWwindow *const lhs, const window &rhs)
{
  return lhs == static_cast<GLFWwindow *const>(rhs);
}

inline
bool operator!=(GLFWwindow *const lhs, const window &rhs)
{
  return ! (lhs == rhs);
}

} // namespace runtime
} // namespace g2

