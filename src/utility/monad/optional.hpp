#pragma once

#include "utility/monad.hpp"

#include <boost/optional.hpp>

namespace g2 {
namespace monad {

// Partial specialization of the monadic bind operator for boost::optional.
template <typename A, typename B>
constexpr boost::optional<B> bind(boost::optional<A>, std::function<boost::optional<B>(A)>);

// Partial specialization of the monadic unit operator for boost::optional.
template <typename A>
constexpr boost::optional<A> unit(A);

// Implementations.

template <typename A, typename B>
constexpr boost::optional<B> bind(boost::optional<A> a, std::function<boost::optional<B>(A)> f)
{
  if (a) {
    return f(std::move(*a));
  } else {
    return boost::none;
  }
}

template <typename A>
constexpr boost::optional<A> unit(A a)
{
  return { std::move(a) };
}

} // namespace monad
} // namespace g2

