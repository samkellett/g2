#pragma once

namespace g2 {

template <typename T>
struct type_
{
  using type = T;
};

template <typename T>
constexpr auto type = type_<T>{};

} // namespace g2

