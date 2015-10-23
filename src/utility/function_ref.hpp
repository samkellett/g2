#pragma once

#include "utility/concepts/requires.hpp"

#include <cstdint>
#include <memory>

namespace g2 {

template<typename Fn> class function_ref;

template<typename Ret, typename ...Params>
class function_ref<Ret(Params...)> {
  Ret (*callback)(intptr_t callable, Params ...params);
  intptr_t callable;

  template<typename Callable>
  static Ret callback_fn(intptr_t callable, Params ...params) {
    return (*reinterpret_cast<Callable*>(callable))(
        std::forward<Params>(params)...);
  }

public:
  template <typename Callable>
  function_ref(Callable &&c,
               typename std::enable_if<
                   !std::is_same<typename std::remove_reference<Callable>::type,
                                 function_ref>::value>::type * = nullptr)
      : callback(callback_fn<typename std::remove_reference<Callable>::type>),
        callable(reinterpret_cast<intptr_t>(&c)) {}
  Ret operator()(Params ...params) const {
    return callback(callable, std::forward<Params>(params)...);
  }
};

//template <typename F>
//class function_ref;
//
//template <typename Ret, typename ...Args>
//class function_ref<Ret(Args...)>
//{
//public:
//  template <typename F,
//    requires_t<! std::is_same<std::remove_reference_t<F>, function_ref>{}>>
//  function_ref(F &&fn);
//
//  Ret operator()(Args&&... args) const;
//
//private:
//  Ret(*callback_)(std::intptr_t callable, Args... args);
//  std::intptr_t callable_;
//
//  template <typename F>
//  static Ret callback_fn(std::intptr_t, Args&& ...args);
//};
//
//template <typename Ret, typename ...Args>
//template <typename F,
//  requires_t<! std::is_same<std::remove_reference_t<F>, function_ref<Ret(Args...)>>{}>>
//function_ref<Ret(Args...)>::function_ref(F &&fn) :
//  callback_(callback_fn<std::remove_reference_t<F>>),
//  callable_(reinterpret_cast<std::intptr_t>(std::addressof(fn)))
//{
//}
//
//template <typename Ret, typename ...Args>
//Ret function_ref<Ret(Args...)>::operator()(Args&&... args) const
//{
//  return callback_(callable_, std::forward<Args>(args)...);
//}
//
//template <typename Ret, typename ...Args>
//template <typename F>
//Ret function_ref<Ret(Args...)>::callback_fn(std::intptr_t callable, Args&&... args)
//{
//  return (*reinterpret_cast<F *>(callable))(std::forward<Args>(args)...);
//}

} // namespace g2

