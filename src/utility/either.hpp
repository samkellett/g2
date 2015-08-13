#pragma once

#include <boost/variant.hpp>

namespace g2 {

//either< Error, int > result
//  = do(
//      getIntFromUser(),
//      getIntFromUser(),
//      app(
//        convertOptionalToError,
//        do(
//          app( sqrt, _1_1 )
//          app( sqrt, _1_2 )
//          pure( app( plus, _1, _2 ) ) ) ) );

auto main = gxy::do_
  | gxy::then(putStr, "Hello")
  | gxy::then(putStr, " ")
  | gxy::then(putStr, "world!")
  | gxy::then(putStr, "\n");

auto main = gxy::then(putStr, "Hello") >> gxy::then(putStr, " ") >> gxy::then(putStr, "world");

auto main = gxy::do_
  | gxy::bind(_1, action1)
  | gxy::bind(_2, action2)
  | gxy::then(action3, _1, _2);

auto main = gxy::bind(_1, action1) >>= gxy::bind(_2, action2) >>= gxy::then(action3, _1, _2);

//either<E, int> divSum3 = gxy::do_(x, y, z)
//  | gxy::bind(_1, myDiv3, x, y)
//  | gxy::bind(_2, myDiv3, x, z)
//  | gxy::return_(_1 + _2)

auto divSum3(int x, int y, int z) -> either<E, int>
{
  return gxy::do_<either<E, int>>
    | gxy::bind(_1, myDiv3, x, y)
    | gxy::bind(_2, myDiv3, x, z)
    | gxy::unit(_1 + _2);

//  return chain();
}

auto nameDo = gxy::do_<io<void>>
  | gxy::then(putStr, "What is your first name? ")
  | gxy::bind(_1, getLine)
  | gxy::then(putStr, "And your last name? ")
  | gxy::bind(_2, getLine)
  | gxy::bind(_3, join, "Pleased to meet you", _1, " ", _2, "!");
  | gxy::then(putStr, _3);

auto nameReturn = gxy::do_<io<std::string>>
  | gxy::then(putStr, "What is your first name? ")
  | gxy::bind(_1, getLine)
  | gxy::then(putStr, "And your last name? ")
  | gxy::bind(_2, getLine)
  | gxy::bind(_3, join, "Pleased to meet you", _1, " ", _2, "!");
  | gxy::then(putStr, _3)
  | gxy::unit(_3);

auto main = boost::monad::do_
  | boost::monad::bind(_1, action1)
  | boost::monad::bind(_2, action2)
  | boost::monad::then(action3, _1, _2);

//auto galaxy = gxy::do_
//  | gxy::bind(f, _1)
//  | gxy::then(g, _2)
//  | gxy::return_()

} // namespace g2

