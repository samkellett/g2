/* Requirements:
 *  - no dynamic allocations
 *  - no RTTI
 *  - works with r + l value references
 *  - moveable if all of T is moveable
 *  - ditto for copyable
 *  - visitation (inc rvalue access)
 *  - recursive variants? (recursive_wrapper can use in-place on buffer?)
 */
#pragma once

#include "utility/concepts/requires.hpp"

#include "utility/variant/nullvariant.hpp"

#include "utility/variant/detail/tagged_union.hpp"

#include <meta/meta.hpp>

#include <type_traits>

namespace g2 {
namespace utils {

template <typename... Ts>
class variant final
{
public:
  using types = meta::list<Ts...>;
  static constexpr std::size_t size = types::size();

private:
  // && is_xxxx_assignable?
  static constexpr bool is_moveable = meta::all_of<types, meta::quote<std::is_move_constructible>>{};
  static constexpr bool is_copyable = meta::all_of<types, meta::quote<std::is_copy_constructible>>{};

  static_assert(meta::unique<types>::size() == size, "variant must not contain duplicate types.");

public:
  // Construction.
  constexpr variant() noexcept = default;
  constexpr variant(nullvariant_t) noexcept :
    data_{}
  {}

  template <
    requires_t<is_copyable> = 0>
  constexpr variant(const variant &) = default;

  template <
    requires_t<is_moveable> = 0>
  constexpr variant(variant &&) = default;

  template <typename T,
    requires_t<meta::in<types, T>{}> = 0>
  constexpr explicit variant(T t) = default;

  // Assignment.
  constexpr variant &operator=(nullvariant_t) noexcept = default;

  template <
    requires_t<is_copyable> = 0>
  constexpr variant &operator=(const variant &) = default;

  template <
    requires_t<is_moveable> = 0>
  constexpr variant &operator=(variant &&) = default; // noexcept(...);

  template <typename T,
    requires_t<meta::in<types, T>{}> = 0>
  constexpr variant &operator=(T t) :
    data{std::move(t)}
  {}

  // Destruction.
  ~variant() = default;

  // Swap.
  constexpr void swap(variant &); // noexcept(...);

  // In-place construction.
  template <typename T, typename... Args,
    requires_t<meta::in<types, T>{}> = 0>
  constexpr void emplace(Args&&... args);

  // Access.
  template <typename T,
    requires_t<meta::in<types, T>{}> = 0>
  constexpr const T &get() const &;

  template <typename T,
    requires_t<meta::in<types, T>{}> = 0>
  constexpr T &get() &;

  // Observers.
  constexpr explicit operator bool() const noexcept;
  constexpr std::size_t which() const noexcept;

  constexpr void *target() noexcept;
  constexpr const void *target() const noexcept;

private:
  detail::tagged_union<types> data_;
};

} // namespace utils
} // namespace g2

namespace std {

// template<variant<Ts...>>
// // requires(...)
// hash {
//
// };

};

// using my_variant = variant<int, char, long>;

// template <typename Visitor, typename Variant>
//   // requires Visitor has result_type defined
//   //    has a call operator for each type in Variant::types
//   //    that returns result_type.
//   // requires Variant is a utils::variant<Ts...>
// struct visitor {
//   template <typename F, typename... Args>
//   struct applicator {
//     using return_type = typename Variant::return_type;
//     using function_type = return_type(*)(F fn, void *target, Args... args);

//     template <typename T>
//     static return_type apply(F fn, void *target, Args... args)
//     {
//       return fn(*static_cast<T *>(target), std::forward<Args>(args)...);
//     }
//   };

//   visitor(Variant v) {
//     using applicator_t = applicator<
//   }
// };

// struct my_visitor : utils::visitor<my_visitor, my_variant>{
//   using result_type = bool;

//   template <typename T>
//   result_type operator()(T) { return true; }
// };

// my_variant v;
// bool result = my_visitor(v);
