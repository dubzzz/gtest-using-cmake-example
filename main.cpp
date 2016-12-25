#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

#include "gtest/gtest.h" // gtest must be build using /MTd or /MT -DCMAKE_CXX_FLAGS_DEBUG="/MTd"

std::vector<unsigned long long> build_factorials(unsigned num)
{
  if (num == 0)
  {
    return {};
  }
  std::vector<unsigned long long> vs(num);
  vs[0] = 1;
  std::iota(std::next(std::begin(vs)), std::end(vs), 1);
  std::transform(std::begin(vs), std::prev(std::end(vs))
      , std::next(std::begin(vs))
      , std::next(std::begin(vs))
      , std::multiplies<unsigned long long>());
  return vs;
}

TEST(TEST_NAME, NoValue)
{
  std::vector<unsigned long long> expected = {  };
  ASSERT_EQ(expected, build_factorials(0));
}

TEST(TEST_NAME, SpecificNumberOfValues)
{
  std::vector<unsigned long long> expected = { 1, 1, 2, 6, 24, 120, 720 };
  ASSERT_EQ(expected, build_factorials(7));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  int ret { RUN_ALL_TESTS() };
  return ret;
}
