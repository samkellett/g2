#include "utility/monad/optional.hpp"

#include <boost/algorithm/string/case_conv.hpp>

#include <gtest/gtest.h>

using namespace g2;
using namespace std::string_literals;

boost::optional<std::string> to_maybe_up(std::string str)
{
  return boost::algorithm::to_upper_copy(std::move(str));
}

TEST(Bind, Function)
{
  auto a(boost::make_optional("badger"s));

  auto result(monad::bind<std::string, std::string>(a, &to_maybe_up));
  ASSERT_EQ(boost::make_optional("BADGER"s), result);
}

TEST(BindOperator, Lambda)
{
  using monad::operator>>;

  auto a(boost::make_optional("badger"s));

  auto result(a >> +[](std::string &&a1) { return to_maybe_up(a1); });
  ASSERT_EQ(boost::make_optional("BADGER"), result);
}

//TEST(BindOperator, ChainOfLambdas)
//{
//  using monad::operator>>;
//
//  auto a(boost::make_optional(1));
//
//  auto result(
//    a >> [](int i) { return boost::make_optional(i + 10); }
//      >> [](int i) { return boost::make_optional(std::to_string(i)); }
//      >> [](std::string s) { return s + " badgers"s; }
//      >> [](std::string s) { return to_maybe_up(s); }
//  );
//
//  ASSERT_EQ(boost::make_optional("11 BADGERS"s), result);
//}

