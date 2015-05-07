#pragma once

#include "utility/current_fn.hpp"

#include <stdexcept>
#include <string>

class unsupported_error : public std::runtime_error
{
public:
  unsupported_error(const std::string &func);
  unsupported_error(const char *func);
};

unsupported_error::unsupported_error(const std::string &func) : runtime_error{func}
{
}

unsupported_error::unsupported_error(const char *func) : runtime_error{func}
{
}
