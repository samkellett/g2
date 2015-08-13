#pragma once

#include <utility>

namespace g2 {

template <char... Cs>
using character_sequence = std::integer_sequence<char, Cs...>;

inline namespace literals {

template <typename T, T... Cs>
constexpr auto operator""_s()
{
  return character_sequence<Cs...>{};
}

} // namespace literals
} // namespace g2

