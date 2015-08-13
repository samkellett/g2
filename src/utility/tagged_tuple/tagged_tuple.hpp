#pragma once

#include "utility/concepts/requires.hpp"

#include "utility/tagged_tuple/tag.hpp"

#include <meta/meta.hpp>

namespace g2 {

namespace detail {

struct get_tag
{
  template <typename Tag>
  using apply = typename Tag::tag_type;
};

struct get_value
{
  template <typename Tag>
  using apply = typename Tag::value_type;
};

} // namespace detail

template <typename ...Ts>
  // requires_t<Tag<Ts> && ...> = 0>
class tagged_tuple_
{
  using tagged_types = meta::list<Ts...>;

public:
  using tag_types = meta::transform<tagged_types, detail::get_tag>;
  using value_types = meta::transform<tagged_types, detail::get_value>;

  tagged_tuple_() = delete;

  tagged_tuple_(const tagged_tuple_ &) = default;
  tagged_tuple_(tagged_tuple_ &&) = default;

  tagged_tuple_ &operator=(const tagged_tuple_ &) = delete;
  tagged_tuple_ &operator=(tagged_tuple_ &&) = delete;

  template <typename Tag> decltype(auto) get() const &;
  template <typename Tag> decltype(auto) get() &&;

  bool operator==(const tagged_tuple_ &o);
  bool operator!=(const tagged_tuple_ &o);

private:
  using tuple_type = meta::apply_list<meta::quote<std::tuple>, value_types>;

  tuple_type data_;
};

template <typename ...Ts>
template <typename Tag>
inline
decltype(auto) tagged_tuple_<Ts...>::get() const &
{
  using index = meta::find_index<tag_types, Tag>;
  static_assert(index{} != meta::npos{}, "Unknown tag.");

  return std::get<index{}>(static_cast<const tuple_type&>(data_));
}

template <typename ...Ts>
template <typename Tag>
inline
decltype(auto) tagged_tuple_<Ts...>::get() &&
{
  using index = meta::find_index<tag_types, Tag>;
  static_assert(index{} != meta::npos{}, "Unknown tag.");

  return std::get<index{}>(static_cast<tuple_type &&>(data_));
}

template <typename ...Ts>
bool tagged_tuple_<Ts...>::operator==(const tagged_tuple_<Ts...> &o)
{
  return data_ == o.data_;
}

template <typename ...Ts>
bool tagged_tuple_<Ts...>::operator!=(const tagged_tuple_<Ts...> &o)
{
  return data_ != o.data_;
}

template <typename... Tags>
auto tagged_tuple(Tags&&...) -> tagged_tuple_<Tags...>;

using limit = decltype(tagged_tuple(
  "offset"_tag = type<std::size_t>,
  "limit"_tag = type<std::size_t>
));

} // namespace g2

