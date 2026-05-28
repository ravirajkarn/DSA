#include <gtest/gtest.h>

#include <vector>

#include "selection_sort.hpp"

// 1. Edge Case: Empty Array
TEST(SelectionSortTest, EmptyArray) {
  std::vector<int> arr = {};
  std::vector<int> expected = {};
  selectionSort(arr);
  EXPECT_EQ(arr, expected);
}

// 2. Edge Case: Single Element
TEST(SelectionSortTest, SingleElement) {
  std::vector<int> arr = {42};
  std::vector<int> expected = {42};
  selectionSort(arr);
  EXPECT_EQ(arr, expected);
}

// 3. Standard Case: Typical Unsorted Array
TEST(SelectionSortTest, TypicalUnsorted) {
  std::vector<int> arr = {64, 25, 12, 22, 11};
  std::vector<int> expected = {11, 12, 22, 25, 64};
  selectionSort(arr);
  EXPECT_EQ(arr, expected);
}

// 4. Best Case: Already Sorted Array
TEST(SelectionSortTest, AlreadySorted) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  std::vector<int> expected = {1, 2, 3, 4, 5};
  selectionSort(arr);
  EXPECT_EQ(arr, expected);
}

// 5. Worst Case: Reverse Sorted Array
TEST(SelectionSortTest, ReverseSorted) {
  std::vector<int> arr = {9, 7, 5, 3, 1};
  std::vector<int> expected = {1, 3, 5, 7, 9};
  selectionSort(arr);
  EXPECT_EQ(arr, expected);
}

// 6. Boundary Case: Array With Duplicates
TEST(SelectionSortTest, WithDuplicates) {
  std::vector<int> arr = {4, 2, 4, 3, 1, 2};
  std::vector<int> expected = {1, 2, 2, 3, 4, 4};
  selectionSort(arr);
  EXPECT_EQ(arr, expected);
}

// 7. Data Type Edge Case: Negative Numbers
TEST(SelectionSortTest, NegativeNumbers) {
  std::vector<int> arr = {-5, 3, -1, 0, -10};
  std::vector<int> expected = {-10, -5, -1, 0, 3};
  selectionSort(arr);
  EXPECT_EQ(arr, expected);
}

// 8. Boundary Case: All Identical Elements
TEST(SelectionSortTest, AllIdenticalElements) {
  std::vector<int> arr = {7, 7, 7, 7};
  std::vector<int> expected = {7, 7, 7, 7};
  selectionSort(arr);
  EXPECT_EQ(arr, expected);
}