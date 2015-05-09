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
  constexpr auto operator()(T &&t) -> decltype(std::declval<G>()(std::declval<F>()(std::forward<T>(t))))
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

} // namespace utils
} // namespace g2
