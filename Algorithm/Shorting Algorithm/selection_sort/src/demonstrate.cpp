#include <fmt/core.h>
#include <random>
#include "selection_sort.hpp"

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution distribution(0,100);
    
    std::vector<int> data;
    
    for (int i = 0; i < 10; i++) data.push_back(distribution(gen));
    
    fmt::print("Unordered list: ");
    for (const auto& element : data) fmt::print(" {} ", element);
    
    secsort(data);
       
    fmt::print("\n\nOrdered list: ");
    for (const auto& element : data) fmt::print(" {} ", element);
    
}