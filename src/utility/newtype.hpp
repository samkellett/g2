#pragma once

#include <memory>
#include <type_traits>

namespace g2 {

template <typename Newtype, typename T>
class newtype
{
  static_assert(! std::is_reference<T>{});
  static_assert(! std::is_pointer<T>{});

public:
  using type = T;

  using reference_type = std::add_lvalue_reference_t<type>;
  using reference_const_type = std::add_const_t<type>;
  using rvalue_reference_type = std::add_rvalue_reference_t<type>;

  using pointer_type = std::add_pointer_t<type>;
  using pointer_const_type = std::add_const_t<pointer_type>;

  template <typename ...Args>
  explicit newtype(Args&& ...args);

  explicit newtype(type &&t);

  newtype() = default;
  newtype(const newtype &) = default;
  newtype(newtype &&) = default;

  newtype &operator=(const newtype &) = default;
  newtype &operator=(newtype &&) = default;

  reference_const_type get() const &;
  reference_type get() &;

  reference_const_type operator*() const &;
  reference_type operator*() &;
  rvalue_reference_type operator*() &&;

  pointer_const_type operator->() const;
  pointer_type operator->();

private:
  type value_;
};

template <typename Newtype, typename T>
template <typename ...Args>
newtype<Newtype, T>::newtype(Args&& ...args) :
  value_(std::forward<Args>(args)...)
{
}

template <typename Newtype, typename T>
inline
newtype<Newtype, T>::newtype(type &&t) :
  value_(std::forward<T>(t))
{
}

template <typename Newtype, typename T>
inline
auto newtype<Newtype, T>::get() const & -> reference_const_type
{
  return value_;
}

template <typename Newtype, typename T>
inline
auto newtype<Newtype, T>::get() & -> reference_type
{
  return value_;
}

template <typename Newtype, typename T>
inline
auto newtype<Newtype, T>::operator*() const & -> reference_const_type
{
  return get();
}

template <typename Newtype, typename T>
inline
auto newtype<Newtype, T>::operator*() & -> reference_type
{
  return get();
}

template <typename Newtype, typename T>
inline
auto newtype<Newtype, T>::operator*() && -> rvalue_reference_type
{
  return std::move(get());
}

template <typename Newtype, typename T>
inline
auto newtype<Newtype, T>::operator->() const -> pointer_const_type
{
  return std::addressof(get());
}

template <typename Newtype, typename T>
inline
auto newtype<Newtype, T>::operator->() -> pointer_type
{
  return std::addressof(get());
}

} // namespace g2

