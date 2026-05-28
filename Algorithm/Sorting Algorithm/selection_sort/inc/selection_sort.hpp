#pragma once

#include <print>
#include <vector>

void selectionSort(std::vector<int>& nums) {
  if (nums.empty()) return;
  for (int index = 0; index < nums.size(); ++index) {
    int selected = index;
    for (size_t selector = index + 1; selector < nums.size(); ++selector) {
      if (nums[selector] < nums[selected]) selected = selector;
    }
    if (index != selected) std::swap(nums.at(index), nums[selected]);
  }
}
