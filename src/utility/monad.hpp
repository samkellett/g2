#pragma once

#include <functional>

namespace g2 {
namespace monad {

// Declaration of a generic monadic bind operation. Should the monad M implement this it
// will be able to use the >> operator to chain together functions.
template <template <typename> class M, typename A, typename B>
constexpr M<B> bind(M<A>, std::function<M<B>(A)>);

// Declaration of a generic monadic return operation.
template <template <typename> class M, typename A>
constexpr M<A> unit(A);

// Monadic >> operator implemented in terms of bind(...).
template <template <typename> class M, typename A, typename B>
constexpr auto operator>>(M<A> &&m, std::function<M<B>(A)> &&f)
{
  return bind<M, A, B>(std::forward<M<A>>(m), std::forward<std::function<M<B>(A)>>(f));
}

} // namespace monad
} // namespace g2

