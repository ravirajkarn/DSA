/**
 * @file selection_sort.cpp
 * @author Sumit Kumar (ravirajkarn@outlook.com)
 * @brief This is binary search algorithm created my me.
 * @version 0.1
 * @date 2026-05-20
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <selection_sort.hpp>

int main() {
  std::vector<int> number = {64, 25, 12, 22, 11, -1, 0, 3, 5, 9, 12};
  std::print("the numbe befor: {}\n", number);
  selectionSort(number);
  std::print("the numbe after: {}\n", number);
  return 0;
}
