# Selection Sort
[![C++](https://img.shields.io/badge/C++-23-blue.svg)](https://isocpp.org/) [![CMake](https://img.shields.io/badge/CMake-4.0+-green.svg)](https://cmake.org/) [![Conan](https://img.shields.io/badge/Conan-2.0-lightgrey.svg)](https://conan.io/) [![GTest](https://img.shields.io/badge/Testing-Google%20Test-yellow.svg)](https://github.com/google/googletest)

## Overview
This repository documents my journey of understanding, implementing, and refining the **Selection Sort** algorithm in C++. The project is structured professionally using **CMake** for build configuration, **Conan** for package management, and **Google Test (GTest)** for robust unit testing.

Selection sort is a simple, in-place comparison sorting algorithm. It works by dividing the input list into two parts: a sorted sublist of items which is built up from left to right at the front (left) of the list, and a sublist of the remaining unsorted items that occupy the rest of the list. Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by finding the smallest element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element, and moving the sublist boundaries one element to the right.

![Selection Sort](<assets/selectionSort.gif>)

> [!important]
> - Selection sort always performs $O(n^2)$ comparisons regardless of the initial order of the array, making it highly predictable but inefficient for large datasets.

## Implementation

> [!success] CPP Implementation
>
> ```cpp
> #include <print>
> #include <vector>
> #include <utility>
> 
> void selectionSort(std::vector<int>& nums) {
>  if (nums.empty()) return;
>  for (int index = 0; index < nums.size(); ++index) {
>    int selected = index;
>    for (size_t selector = index + 1; selector < nums.size(); ++selector) {
>      if (nums[selector] < nums[selected]) selected = selector;
>    }
>    if (index != selected) std::swap(nums.at(index), nums[selected]);
>  }
>}
>
> 
> int main() {
>   std::vector<int> number = {64, 25, 12, 22, 11, -1, 0, 3, 5, 9, 12};
>   std::print("{}\n", number);
>   selectionSort(number);
>   std::print("the number sorted is: {}\n", number);
>   return 0;
> }
> ```

>[!success] Python Implementation
>```python 
># This code is created by me
>def selection_sort(nums):
>    if len(nums) < 1:
>        return nums
>    for index in range(len(nums)):
>        selected = index
>        selector = index
>        for selector in range(index + 1, len(nums)):
>            if nums[selector] < nums[selected]:
>                selected = selector
>        if index != selected:
>            nums[index], nums[selected] = nums[selected], nums[index]
>
>
>def main():
>    number = [64, 25, 12, 22, 11, -1, 0, 3, 5, 9, 12]
>    selection_sort(number)
>    print(f"the number is: {number}")
>
>
>if __name__ == "__main__":
>    main()
>```

>[!Tip] Time & Space Complexity
>
>- **Best Case: O($n^2$)**
>- **Average Case: O($n^2$)**
>- **Worst case: O($n^2$)**
>- **Space Complexity: O(1)** (In-place sort)

## 🧠 What I Learned

* **Algorithm Mechanics:** Selection sort is intuitive and teaches valuable lessons about nested loops, array boundaries, and in-place swapping without requiring auxiliary arrays.
* **Modern C++23 Features:** Utilized modern C++23 features like `std::print` for cleaner output formatting, bypassing older `std::cout` paradigms.
* **Modern C++ Tooling:** Continued reinforcing best practices for real-world C++ project structure:
  * Using **CMake (`CMakeLists.txt`)** to manage targets, C++23 compiler standards, and linking libraries.
  * Using **Conan (`conanfile.py`)** to cleanly manage dependencies (like GTest).
  * Writing comprehensive unit tests with **GTest**, mathematically proving the sorting logic handles empty vectors, duplicates, negative numbers, and reverse-sorted lists gracefully.

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
./build/Release/gemini_test
```