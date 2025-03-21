#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <vector>

int bubble_sort(std::vector<int> &arr){
    int n = arr.size();
    
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    fmt::print(fmt::fg(fmt::color::yellow), "Unsorted array: {}", arr[0]);
    return 0;
}