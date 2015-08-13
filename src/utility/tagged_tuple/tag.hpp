#pragma once

#include "utility/character_sequence.hpp"
#include "utility/type.hpp"

namespace g2 {

template <typename Tag>
struct tag;

template <typename Tag, typename Type>
struct typed_tag;

template <typename Tag>
struct tag
{
  using type = Tag;

  template <typename T>
  auto operator=(type_<T>) const -> typed_tag<type, T>;
};

template <typename Tag, typename Type>
struct typed_tag
{
  using tag_type = Tag;
  using value_type = Type;
};

inline namespace literals {

template <typename T, T... Cs>
constexpr auto operator""_tag()
{
  return tag<character_sequence<Cs...>>{};
}

} // namespace literals

} // namespace g2

