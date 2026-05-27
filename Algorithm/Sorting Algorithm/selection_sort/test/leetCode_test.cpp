#include <gtest/gtest.h>
#include <vector>
#include "binary_search.hpp" // Assuming this is where my_binary_search is declared

// 1. Edge Case: Empty Array
// The function should safely return -1 without throwing out-of-bounds errors.
TEST(BinarySearchTest, EmptyArray) {
    std::vector<int> num = {};
    EXPECT_EQ(my_binary_search(num, 5), -1);
}

// 2. Edge Case: Single Element Array
// Tests if the logic works when low == high right from the start.
TEST(BinarySearchTest, SingleElement) {
    std::vector<int> num = {5};
    EXPECT_EQ(my_binary_search(num, 5), 0);  // Target is present
    EXPECT_EQ(my_binary_search(num, 2), -1); // Target is smaller
    EXPECT_EQ(my_binary_search(num, 8), -1); // Target is larger
}

// 3. Edge Case: Two Element Array
// Tests if the midpoint calculations correctly round down and don't get stuck.
TEST(BinarySearchTest, TwoElements) {
    std::vector<int> num = {2, 8};
    EXPECT_EQ(my_binary_search(num, 2), 0);  // First element
    EXPECT_EQ(my_binary_search(num, 8), 1);  // Second element
    EXPECT_EQ(my_binary_search(num, 0), -1); // Out of bounds (left)
    EXPECT_EQ(my_binary_search(num, 5), -1); // Missing (middle)
    EXPECT_EQ(my_binary_search(num, 10), -1); // Out of bounds (right)
}

// 4. Standard Case: Even Length Array
// Checks array traversal where there is no true "middle" element.
TEST(BinarySearchTest, EvenLengthArray) {
    std::vector<int> num = {-1, 0, 3, 5, 9, 12}; // Size 6
    EXPECT_EQ(my_binary_search(num, -1), 0);     // Left boundary
    EXPECT_EQ(my_binary_search(num, 12), 5);     // Right boundary
    EXPECT_EQ(my_binary_search(num, 3), 2);      // Left of center
    EXPECT_EQ(my_binary_search(num, 5), 3);      // Right of center
    EXPECT_EQ(my_binary_search(num, 2), -1);     // Missing element
}

// 5. Standard Case: Odd Length Array
// Checks array traversal where there is an exact middle element.
TEST(BinarySearchTest, OddLengthArray) {
    std::vector<int> num = {-1, 0, 3, 5, 9, 12, 15}; // Size 7
    EXPECT_EQ(my_binary_search(num, 5), 3);          // Exact middle
    EXPECT_EQ(my_binary_search(num, -1), 0);         // Left boundary
    EXPECT_EQ(my_binary_search(num, 15), 6);         // Right boundary
    EXPECT_EQ(my_binary_search(num, 0), 1);          // Left half
    EXPECT_EQ(my_binary_search(num, 12), 5);         // Right half
}

// 6. Missing Elements (Out of Bounds & Inner Gaps)
// Thoroughly checks scenarios where the target does not exist.
TEST(BinarySearchTest, TargetNotPresent) {
    std::vector<int> num = {10, 20, 30, 40, 50};
    EXPECT_EQ(my_binary_search(num, 5), -1);  // Smaller than all elements
    EXPECT_EQ(my_binary_search(num, 55), -1); // Larger than all elements
    EXPECT_EQ(my_binary_search(num, 25), -1); // Falls exactly between two elements
}

// 7. All Negative Numbers
// Ensures math logic holds up when dealing exclusively with negative integers.
TEST(BinarySearchTest, AllNegativeNumbers) {
    std::vector<int> num = {-50, -40, -30, -20, -10};
    EXPECT_EQ(my_binary_search(num, -30), 2);
    EXPECT_EQ(my_binary_search(num, -10), 4);
    EXPECT_EQ(my_binary_search(num, -5), -1);
}