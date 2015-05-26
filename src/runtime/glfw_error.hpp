#pragma once

#include <stdexcept>
#include <string>

namespace g2 {

void glfw_error_callback(int error, const char *description);

class glfw_error : public std::runtime_error
{
public:
  glfw_error(int, const std::string &error);
  glfw_error(int, const char *error);

  int error() const;

private:
  int error_;
};

void glfw_error_callback(int error, const char *description)
{
  throw glfw_error(error, description);
}

glfw_error::glfw_error(int error, const std::string &desc) : glfw_error{error, desc.c_str()}
{
}

glfw_error::glfw_error(int error, const char *desc) : runtime_error{desc},
  error_(error)
{
}

int glfw_error::error() const
{
  return error_;
}

} // namespace g2

