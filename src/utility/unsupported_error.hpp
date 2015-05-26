#pragma once

#include "utility/current_fn.hpp"

#include <stdexcept>
#include <string>

namespace g2 {

class unsupported_error : public std::runtime_error
{
public:
  unsupported_error(const std::string &func);
  unsupported_error(const char *func);
};

unsupported_error::unsupported_error(const std::string &func) : unsupported_error{func.c_str()}
{
}

unsupported_error::unsupported_error(const char *func) : runtime_error{func}
{
}

} // namespace g2

