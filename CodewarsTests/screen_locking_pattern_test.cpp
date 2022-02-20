#include "pch.h"

#include "../../Codewars/Codewars/screen_locking_pattern.cpp"

TEST(screen_locking_pattern, handles_edge_cases) {
  EXPECT_EQ(countPatternsFrom('A', 0), 0);
  EXPECT_EQ(countPatternsFrom('A', 10), 0);
  EXPECT_EQ(countPatternsFrom('B', 1), 1);

}

TEST(screen_locking_pattern, handles_small_numbers)
{
    EXPECT_EQ(countPatternsFrom('C', 2), 5);
    EXPECT_EQ(countPatternsFrom('D', 3), 37);
    EXPECT_EQ(countPatternsFrom('E', 4), 256);
}

TEST(screen_locking_pattern, handles_large)
{
    EXPECT_EQ(countPatternsFrom('E', 8), 23280);
}