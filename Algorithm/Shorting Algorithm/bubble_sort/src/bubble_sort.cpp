#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>

void bubble_sort(int arr[], int n){
    bool isSorted = true;
    for (int j = 0; j < n - 1; j++){
        isSorted = true;
        for (int i = 1; i < n; i++){
            if (arr[i-1] > arr[i]){
                std::swap(arr[i-1], arr[i]);
                isSorted = false;
            }
            fmt::print("i: {}\n", i);
        }
        if (isSorted == true)
            break;
        fmt::print("j: {}\n", j);
    }
}

void print_array(int arr[], int n){
    for (int i = 0; i < n ; i++){
        fmt::print("{} ", arr[i]);
    }
    fmt::print("\n");
}

int main()
{
    int bcd[] = {1,2,3,4,6,5};
    int m = sizeof(bcd) / sizeof(bcd[0]);
    print_array(bcd, m );

    bubble_sort(bcd, m);

    print_array(bcd, m);
    return 0;
}