#pragma once

#include <stdexcept>
#include <string>

class bad_variant_access : public std::logic_error
{
public:
  bad_variant_access(const std::string &what);
  bad_variant_access(const char *what);
};

bad_variant_access::bad_variant_access(const std::string &what) : logic_error{what}
{
}

bad_variant_access::bad_variant_access(const char *what) : logic_error{what}
{
}
