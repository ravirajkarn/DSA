# Binary Search
[![C++](https://img.shields.io/badge/C++-23-blue.svg)](https://isocpp.org/) [![CMake](https://img.shields.io/badge/CMake-4.0+-green.svg)](https://cmake.org/) [![Conan](https://img.shields.io/badge/Conan-2.0-lightgrey.svg)](https://conan.io/) [![GTest](https://img.shields.io/badge/Testing-Google%20Test-yellow.svg)](https://github.com/google/googletest)
## Overview
This repository documents my journey of understanding, implementing, and refining the **Binary Search** algorithm in C++ and Python. The project is structured professionally using **CMake** for build configuration, **Conan** for package management, and **Google Test (GTest)** for robust unit testing.

It divide and concur rule.
We divide an array/list in two part and check for the number. If the number is less then the given number then we check the first half. the first half will again divide into two part and so on. If the number is grater then the given number then we will work on the second half and further divide it and so on. If the number if equal to the number given then we found it!
![[Binary Search.png]]![Binary Search](<assets/binary Search.gif>)

> [!important]
> - Binary search only works when your list is in sorted order.

## Implementation
> [!success] Python Implementation
> The binary_search function takes a sorted array and an item. If the  item is in the array, the function returns its position.
>
> ```python
> # This code is created by me
> def binary_search(nums, target):
>    low = 0 
>    high = len(nums) - 1
>    num = (low + high) // 2
>    mid = nums[num]
>    while low <= high and target >= nums[low] and target <= nums[high]:
>        if mid != target:
>            if mid <= target:
>                low = num
>            else:
>                high = mid
>            num = (low + high) // 2
>            mid = nums[num]
>            if nums[low] == target: return low
>            if nums[high] == target: return high
>            if low == mid: break
>        else:
>            return mid
>    return -1
>        
>def main():
>    number = [11, 12, 13, 14, 16, 17, 18, 19, 110, 111]
>    target = 0
>    print(f"the number is: {binary_search(number, target)}")
>
>if __name__ == "__main__":
>    main()
> ```

> [!success] CPP Implementation
>
> ```Cpp
> #include <iostream>
> #include <vector>
> int my_binary_search(const std::vector<int>& nums, int target) {
>  if (nums.empty()) return -1;
>  int low = 0;
>  int high = nums.size() - 1;
>  int mid = (low + high) / 2;
>  while (low <= high && target >= nums.at(low) && target <= nums.at(high)) {
>    if (nums.at(mid) != target) {
>      if (nums.at(mid) <= target)
>        low = mid;
>      else
>        high = mid;
>      mid = (low + high) / 2;
>      if (nums.at(low) == target) return low;
>      if (nums.at(high) == target) return high;
>      if (low == mid) break;
>    } else
>      return mid;
>  }
>  return -1;
>}
>   
> int main() {
>  std::vector<int> number = {11, 12, 13, 14, 16, 17, 18, 19, 110, 111};
>  int item = 19;
>  std::cout << "the numbe is: " << my_binary_search(number, item) << std::endl;
>  return 0;
> }
> ```

>[!Tip] Time Complexity
>
>- **Best Case: O(1)**
>- **Average Case: O($log(n)$)**
>- **Worst case: O($log(n)$)**

## 🧠 What I Learned

* **Algorithm Precision:** Binary search seems simple on the surface, but off-by-one errors and loop conditions require absolute precision.
* **Production vs. Competitive Code:** I explored how standard library functions work compared to custom implementations, and learned the difference between competitive programming "0ms hacks" (like bitwise parsing and bypassing test runners) and clean, production-ready code.
* **Modern C++ Tooling:** I learned how to set up a real-world C++ project from scratch:
  * Using **CMake (`CMakeLists.txt`)** to manage targets, compiler standards (C++23), and linking libraries.
  * Using **Conan (`conanfile.py`)** to cleanly manage dependencies (like GTest) instead of manually downloading and linking binaries.
  * Writing unit tests with **GTest** to mathematically prove my code works across all expected and unexpected edge cases.

## 🚀 Getting Started

### Prerequisites
* C++ Compiler supporting C++23
* CMake (>= 4.0)
* Conan Package Manager (2.x)

### Build & Run Instructions

**1. Install dependencies using Conan:**
```bash
conan install . --build=missing
```
**2. Configure and Build with CMake:**

```Bash
cmake -G "Ninja" -S . -B build/Release -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=generators/conan_toolchain.cmake

cmake --build build/Release
```

**3. Run the Tests:**

```Bash
cmake --build build/Release --target test
# Or run the test executable directly
./build/Release/leetCode_test
```