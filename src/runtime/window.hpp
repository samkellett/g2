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

  operator GLFWwindow *() const;

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

window::window()
: window_(nullptr, deleter())
{
}

window::window(std::nullptr_t)
: window()
{
}

window::window(GLFWwindow *win)
: window_(win, deleter())
{
}

window &window::operator=(GLFWwindow *window)
{
  window_ = std::unique_ptr<GLFWwindow, deleter>(window, deleter());
  return *this;
}

window::operator GLFWwindow *() const
{
  return window_.get();
}

void window::deleter::operator()(GLFWwindow *window) const
{
  glfwDestroyWindow(window);
}

bool operator==(const window &lhs, const window &rhs)
{
  return static_cast<GLFWwindow *>(lhs) == static_cast<GLFWwindow *>(rhs);
}

bool operator!=(const window &lhs, const window &rhs)
{
  return ! (lhs == rhs);
}

bool operator==(GLFWwindow *const lhs, const window &rhs)
{
  return lhs == static_cast<GLFWwindow *>(rhs);
}

bool operator!=(GLFWwindow *const lhs, const window &rhs)
{
  return ! (lhs == rhs);
}

} // namespace runtime
} // namespace g2

