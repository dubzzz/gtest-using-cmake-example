#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

#include "gtest/gtest.h" // gtest must be build using /MTd or /MT -DCMAKE_CXX_FLAGS_DEBUG="/MTd"

std::vector<int> pushback_failure(unsigned size)
{
  std::vector<int> vs(size);
  std::iota(vs.begin(), vs.end(), 0);
  
  vs.reserve(2 * size);
  std::copy(vs.rbegin(), vs.rend(), std::back_inserter(vs));
  return vs;
}

TEST(TEST_NAME, SpecificNumberOfValuesFailure)
{
  std::vector<int> expected = { 0, 1, 2, 2, 1, 0 };
  ASSERT_EQ(expected, pushback_failure(3));
}

TEST(TEST_NAME, SpecificNumberOfValuesOk)
{
  std::vector<int> expected = { 0, 1, 2, 2, 1, 0 };
  ASSERT_EQ(expected, pushback_failure(3));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  int ret { RUN_ALL_TESTS() };
  return ret;
}
