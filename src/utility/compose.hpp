#pragma once

#include <meta/meta.hpp>

#include <utility>

namespace g2 {
namespace utils {

namespace detail {

template <typename F, typename G>
struct composed
{
public:
  composed()
  : inner_(),
    outer_()
  {
  }

  explicit composed(F f, G g)
  : inner_(std::move(f)),
    outer_(std::move(g))
  {
  }

  template <typename T>
  auto operator()(T t) -> decltype(std::declval<G>()(std::declval<F>()(t)))
  {
    return outer_(inner_(std::move(t)));
  }

private:
  F inner_;
  G outer_;
};

} // namespace detail

// Takes a list of Callable, returns a composition of them all.
// ie. compose<F, G, H> -> composed<composed<F, G>, H>
template <typename... Ts>
  // requires_t<Callable<Ts>...>
using compose = meta::fold<
  meta::pop_front<meta::list<Ts...>>,
  meta::front<meta::list<Ts...>>,
  meta::lambda<meta::_a, meta::_b,
    meta::lazy::apply<meta::quote<detail::composed>, meta::_a, meta::_b>
  >
>;

} // namespace utils
} // namespace g2
