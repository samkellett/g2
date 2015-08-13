#pragma once

#include "utility/static_const.hpp"

#include <type_traits>

namespace g2 {

namespace detail {

template <typename F, typename ...Args,
  typename = decltype(std::declval<F&&>()(std::declval<Args&&>()...))>
constexpr auto is_valid_impl(int)
{
  return std::true_type{};
}

template <typename F, typename ...Args>
constexpr auto is_valid_impl(...)
{
  return std::false_type{};
}

template <typename F>
struct is_valid_fn
{
  template <typename... Args>
  constexpr auto operator()(Args&&...) const
  {
    return is_valid_impl<F, Args&&...>(int{});
  }
};

struct is_valid
{
  template <typename F>
  constexpr auto operator()(F&&) const;

  template <typename F, typename ...Args>
  constexpr auto operator()(F&&, Args&&...) const;
};

template <typename F>
constexpr auto is_valid::operator()(F&&) const
{
  return is_valid_fn<F&&>{};
}

template <typename F, typename ...Args>
constexpr auto is_valid::operator()(F&&, Args&&...) const
{
  return is_valid_impl<F&&, Args&&...>(int{});
}

} // namespace detail

static constexpr auto &is_valid = static_const<detail::is_valid>();

} // namespace g2

