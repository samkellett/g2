#include "utility/ml/max_element.hpp"

using empty_t = meta::list<>;
using nonempty_t = meta::list<char, short, int, long>;
using nonempty_reversed_t = meta::reverse<nonempty_t>;

int main()
{
  using fixtures = meta::list<empty_t, nonempty_t, nonempty_reversed_t>;
  using results = meta::list<meta::size_t<0>, meta::sizeof_<long>, meta::sizeof_<long>>;

  using test_cases = meta::zip<meta::list<fixtures, results>>;

  meta::for_each(test_cases{}, [](auto t) {
    using uut = decltype(t);

    using list = meta::at_c<uut, 0>;
    using expected = meta::at_c<uut, 1>;

    static_assert(
      std::is_same<
        g2::ml::max_element<
          list,
          meta::size_t<0>,
          meta::quote<meta::sizeof_>
        >,
        expected
      >{},
      "Largest type is not correct."
    );
  });
}
