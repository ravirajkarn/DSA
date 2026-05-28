#pragma once

#include <print>
#include <vector>

void selectionSort(std::vector<int>& set) {
  for (int index = 0; index < set.size(); ++index) {
    int selected = index;
    for (int selector = index; selector < set.size(); ++selector) {
      if (set.at(selector) < set.at(selected)) selected = selector;
    }
    std::swap(set.at(index), set.at(selected));
    if (index >= set.size()) break;
  }
}
