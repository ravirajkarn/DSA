#include <iostream>
#include <vector>
int my_binary_search(const std::vector<int>& list, int item) {
  if (list.empty()) return -1;
  int low = 0;
  int high = list.size() - 1;
  int num = (low + high) / 2;
  int mid = list.at(num);
  while (low <= high && mid != item && item >= list.at(low) &&
         item <= list.at(high)) {
    if (item > mid)
      low = num + 1;
    else
      high = num;
    num = (low + high) / 2;
    mid = list.at(num);
    if (mid == item) return num + 1;
  }
  return -1;
}

int main() {
  std::vector<int> number = {11, 12, 13, 14, 16, 17, 18, 19, 110, 111};
  int item = 19;
  std::cout << "the numbe is: " << my_binary_search(number, item) << std::endl;
  return 0;
}