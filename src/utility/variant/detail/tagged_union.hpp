#pragma once

#include <meta/meta.hpp>

namespace g2 {
namespace utils {

namespace detail {

template <typename List>
struct tagged_union;

template <typename... Ts>
struct tagged_union<meta::list<Ts...>>
{
};

} // namespace detail

} // namespace utils
} // namespace g2
