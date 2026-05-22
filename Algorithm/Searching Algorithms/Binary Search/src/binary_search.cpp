/**
 * @file binary_search.cpp
 * @author Sumit Kumar (ravirajkarn@outlook.com)
 * @brief This is binary search algorithm created my me.
 * @version 0.1
 * @date 2026-05-20
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <binary_search.hpp>

int main() {
  // std::vector<std::vector<int>> number = {{-1,0,3,5,9,12},{-1,0,3,5,9,12},{-1,0,5},{-1,0,3,5,9,12}};
  // std::vector<int> target = {9, 2};
  std::vector<int> number = {-1,0,3,5,9,12};
  int target = 9;
  std::print("the numbe is: {}\n ",
             /*number.size()); */ my_binary_search(number, target));
  return 0;
}
