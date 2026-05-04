#include <iostream>
#include "prime_number.hpp"
#include <random>
#include <fmt/core.h>
#include <gmp.h>


void print_prime(auto number){
    for (const auto& prime : number) {
        fmt::print("{}\n", prime);
    }
}

int main() {
    fmt::print("Prime numbers up to 1000:\n");
    print_prime(PrimeNumber::generator::bySieveOfEratosthenes(100));
    print_prime(PrimeNumber::generator::bySieveOfAtkin(100));

    fmt::print("\nA random number is generating.\n");
    std::random_device rd;
    std::mt19937 mt(rd());
    
    int number = mt();
    fmt::print("{0} is a prime number: {1:s}\n",number,PrimeNumber::checker::isPrime(number) );
    
}