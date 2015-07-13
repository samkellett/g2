#include "utility/compose.hpp"

#include <gmock/gmock.h>

#include <boost/format.hpp>

using namespace g2;
using namespace utils;

using testing::_;
using testing::NiceMock;
using testing::Return;

struct f { bool operator()(bool) { return true; }};
struct g { bool operator()(bool) { return true; }};
struct h { bool operator()(bool) { return true; }};

static_assert(std::is_same<compose<f, g>, detail::composed<f, g>>{}, "Functions not composed");
static_assert(
  std::is_same<compose<f, g, h>, detail::composed<detail::composed<f, g>, h>>{},
  "Functions doen't compose."
);

struct kappa {
public:
  MOCK_CONST_METHOD1(Call, int(std::string));

  int operator()(const std::string str) const
  {
    return Call(str);
  }
};

struct lambda {
public:
  MOCK_CONST_METHOD1(Call, float(int));

  float operator()(const int i) const
  {
    return Call(i);
  }
};

template <typename T>
struct proxy {
public:
  proxy(T *t)
  : t_(t)
  {
  }

  // For kappa
  int operator()(const std::string v) const
  {
    return (*t_)(v);
  }

  // For lambda
  float operator()(const int v) const
  {
    return (*t_)(v);
  }

private:
  T *t_;
};

struct ComposeKappaOfLambda : public testing::Test
{
  NiceMock<kappa> k;
  NiceMock<lambda> l;

  compose<proxy<kappa>, proxy<lambda>> uut;

  ComposeKappaOfLambda()
  : k(),
    l(),

    uut(&k, &l)
  {
  }
};

TEST_F(ComposeKappaOfLambda, KappaIsCalled)
{
  EXPECT_CALL(k, Call(_))
    .Times(1);

  uut("badger");
}

TEST_F(ComposeKappaOfLambda, ParameterForwardedToKappa)
{
  EXPECT_CALL(k, Call("badger"))
    .Times(1);

  uut("badger");
}

TEST_F(ComposeKappaOfLambda, LambdaIsCalled)
{
  EXPECT_CALL(l, Call(_))
    .Times(1);

  uut("badger");
}

TEST_F(ComposeKappaOfLambda, KappaReturnValuePropagated)
{
  EXPECT_CALL(k, Call(_))
    .WillOnce(Return(42));

  EXPECT_CALL(l, Call(42))
    .Times(1);

  uut("badger");
}

TEST_F(ComposeKappaOfLambda, LambdaReturnValueReturned)
{
  EXPECT_CALL(l, Call(_))
    .WillOnce(Return(89));

  ASSERT_EQ(89, uut("badger"));
}

int foo(std::string s) { return std::stoi(s); }
double bar(int i) { return double(i * 2); }

TEST(MakeComposed, TwoFunctions_ExpectedOutput)
{
  auto uut(make_composed(&foo, &bar));

  ASSERT_EQ(2.0, uut("1"));
}

std::string quux(double d) { return boost::str(boost::format("%.1f") % d); }

TEST(MakeComposed, Threefunctions_ExpectedOutput)
{
  auto uut(make_composed(&foo, &bar, &quux));

  ASSERT_EQ("2.0", uut("1"));
}

