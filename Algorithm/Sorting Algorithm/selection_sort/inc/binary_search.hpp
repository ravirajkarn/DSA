#pragma once

#include <print>
#include <vector>

//! my_binary_search() this code have many flows:
//! 1. I expected to have a sorted list.
int my_binary_search(const std::vector<int>& nums, int target) {
  if (nums.empty()) return -1;
  int low = 0;
  int high = nums.size() - 1;
  int mid = (low + high) / 2;
  while (low <= high && target >= nums.at(low) && target <= nums.at(high)) {
    if (nums.at(mid) != target) {
      if (nums.at(mid) <= target)
        low = mid;
      else
        high = mid;
      mid = (low + high) / 2;
      if (nums.at(low) == target) return low;
      if (nums.at(high) == target) return high;
      if (low == mid) break;
    } else
      return mid;
  }
  return -1;
}
