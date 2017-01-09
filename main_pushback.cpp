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

std::reverse_iterator<const int*> fixed_rbegin(std::vector<int> const& vs) { return std::reverse_iterator<const int*>{ vs.data() + vs.size() }; }
std::reverse_iterator<const int*> fixed_rend(std::vector<int> const& vs) { return std::reverse_iterator<const int*>{ vs.data() }; }
std::vector<int> pushback_ok(unsigned size)
{
  std::vector<int> vs(size);
  std::iota(vs.begin(), vs.end(), 0);
  
  vs.reserve(2 * size);
  std::copy(fixed_rbegin(vs), fixed_rend(vs), std::back_inserter(vs));
  return vs;
}

TEST(TEST_NAME, SpecificNumberOfValuesFailure)
{
#ifdef _MSC_VER
  EXPECT_FATAL_FAILURE(
      ASSERT_DEATH(pushback_failure(3), "Should crash under when using Visual Studio")
      , "Should crash under when using Visual Studio");
#else
  std::vector<int> expected = { 0, 1, 2, 2, 1, 0 };
  ASSERT_EQ(expected, pushback_failure(3));
#endif
}

TEST(TEST_NAME, SpecificNumberOfValuesOk)
{
  std::vector<int> expected = { 0, 1, 2, 2, 1, 0 };
  ASSERT_EQ(expected, pushback_ok(3));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  int ret { RUN_ALL_TESTS() };
  return ret;
}
