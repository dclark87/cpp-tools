/** \file sort_test.cc
 * Unit tests for the cpptools sorting methods.
 *
 * Copyright 2018 Daniel Clark
 */
#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

#include "cpptools/sort.h"


class MergeSortTest : public ::testing::Test {
  protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(MergeSortTest, MergeSort) {
  std::vector<int> unsorted = {12, 0, -1, 24, 8, 42, 81, 28, 3, 12};
  std::vector<int> unsorted2{unsorted};
  std::sort(unsorted.begin(), unsorted.end());
  cpptools::merge_sort(unsorted2, 0, unsorted2.size());
  EXPECT_TRUE(unsorted == unsorted2);
}

