#pragma once

#include <type_traits>

namespace g2 {
namespace concepts {

template <bool T>
using requires_t = std::enable_if_t<T, std::size_t>;

} // concepts

using concepts::requires_t;

} // g2
