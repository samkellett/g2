#pragma once

#include <meta/meta.hpp>

#include <utility>

namespace g2 {
namespace utils {

namespace detail {

template <typename F, typename G>
  // requires_t<Callable<F> && Callable<G>>
struct composed
{
public:
  constexpr composed()
  : inner_(),
    outer_()
  {
  }

  explicit constexpr composed(F f, G g)
  : inner_(std::move(f)),
    outer_(std::move(g))
  {
  }

  template <typename T>
    // requires_t<Copyable<T> || Moveable<T>> ... or maybe not?
  constexpr auto operator()(T &&t) const
  {
    return outer_(inner_(std::forward<T>(t)));
  }

private:
  F inner_;
  G outer_;
};

} // namespace detail

// Takes a list of Callable, returns a composition of them all.
// ie. compose<F, G, H> -> composed<composed<F, G>, H>
template <typename T, typename... Ts>
  // requires_t<Callable<T> && Callable<Ts>...>
using compose = meta::fold<meta::list<Ts...>, T, meta::lambda<meta::_a, meta::_b,
    meta::lazy::apply<meta::quote<detail::composed>, meta::_a, meta::_b>
  >
>;

template <typename F>
constexpr auto make_composed(F &&f)
{
  return std::forward<F>(f);
}

template <typename F, typename G>
constexpr auto make_composed(F &&f, G &&g)
{
  return detail::composed<F, G>(std::forward<F>(f), std::forward<G>(g));
}

template <typename F, typename G, typename... Gs>
constexpr auto make_composed(F &&f, G &&g, Gs&& ...gs)
{
  using detail::composed;

  return make_composed(composed<F, G>(std::forward<F>(f), std::forward<G>(g)), std::forward<Gs>(gs)...);
}

} // namespace utils
} // namespace g2

