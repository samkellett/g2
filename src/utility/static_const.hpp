#pragma once

namespace g2 {

namespace detail {

template <typename T>
struct static_const_storage
{
  static constexpr T value = T{};
};

template <typename T>
constexpr T static_const_storage<T>::value;

} // namespace detail

template <typename T>
constexpr const T &static_const()
{
  return detail::static_const_storage<T>::value;
}

} // namespace g2

