// Given a meta::list, return the type whose value is the greatest given the functor F.
#pragma once

#include <meta/meta.hpp>

namespace g2 {
namespace ml {

namespace detail {

using meta::placeholders::_a;
using meta::placeholders::_b;

template <typename List, typename N, typename F>
using max_element_impl = meta::fold<List, N, meta::lambda<_a, _b,
  meta::lazy::max<_a, meta::lazy::apply<F, _b>>
>>;

} // namespace detail

template <typename List, typename N, typename F>
using max_element = detail::max_element_impl<List, N, F>;

} // namespace ml
} // namespace g2
