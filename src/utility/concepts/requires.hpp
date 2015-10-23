#pragma once

#include <type_traits>

namespace g2 {
namespace concepts {

namespace detail {

enum class defaulted{};

} // namespace detail

template <bool T>
using requires_t = std::enable_if_t<T, detail::defaulted>;

} // concepts

using concepts::requires_t;

} // g2
