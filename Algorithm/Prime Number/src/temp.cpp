#include <iostream>
#include "prime_number.hpp"
#include <fmt/core.h>
#include <gmp.h>

int main() {
    auto primes = PrimeNumber::generator::byEratosthenes(1000);
    fmt::print("Prime numbers up to 1000:\n");
    for (const auto& prime : primes) {
        fmt::print("{}\n", prime);
    }
}