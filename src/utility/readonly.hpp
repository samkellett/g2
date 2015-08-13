#pragma once

#include <memory>
#include <utility>

namespace g2 {

template <typename T>
struct readonly
{
  // Default constructible only if T is also.
  readonly() = default;

  // Copy and move construction.
  readonly(const readonly &) = default;
  readonly(readonly &&) = default;

  // No assignment to readonly values.
  readonly &operator=(const readonly &) = delete;
  readonly &operator=(readonly &&) = delete;

  // Implicit value construction for type T.
  readonly(T &&d);

  // Implicit convertion to const-ref of type T.
  operator const T &() const;

  // Const-pointer access for T.
  const T *const operator->() const;

private:
  T data_;
};

template <typename T>
inline
readonly<T>::readonly(T &&d) :
  data_(std::forward<T>(d))
{
}

template <typename T>
inline
readonly<T>::operator const T &() const
{
  return data_;
}

template <typename T>
inline
const T *const readonly<T>::operator->() const
{
  return std::addressof(data_);
}

} // namespace g2

