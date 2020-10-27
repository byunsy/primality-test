#include <chrono>
#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>

#include "sieves.h"
#include "tools.h"

// ============================================================================
//                                    MAIN
// ============================================================================
int main(void) {
    // Clear screen
    ClearScreen();

    // Number of repetitions or trials to measure the average performance time
    const int rep = 1000;

    // Find primes less than this number
    const int primes_upto = 10000;

    // Initialize duration points to measure performance time
    auto duration1 = 0;
    auto duration2 = 0;
    auto duration3 = 0;

    // ========================================================================
    // 01. SIEVE OF ERATOSTHENES
    // ========================================================================

    PrintHeader(1);

    for (int i = 0; i < rep; i++) {
        // Timer start point
        const auto t1 = std::chrono::high_resolution_clock::now();

        // Explore primes using Sieve of Eratosthenes
        std::pair<int *, int> ret_primes1 = SieveEratosthenes(primes_upto);

        // Timer end point
        const auto t2 = std::chrono::high_resolution_clock::now();

        // Calculate performance time
        duration1 +=
            std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                .count();

        // Print the primes found
        if (i == rep - 1) {
            PrintArray(ret_primes1.first, ret_primes1.second);
        }

        delete[] ret_primes1.first;
    }

    std::cout << "Sieve of Eratosthenes Performance Time: " << duration1 / rep
              << " microseconds.\n\n";  // Average duration

    // ========================================================================
    // 02. SIEVE OF SUNDARAM
    // ========================================================================

    PrintHeader(2);

    for (int i = 0; i < rep; i++) {
        // Timer start point
        const auto t3 = std::chrono::high_resolution_clock::now();

        // Explore primes using Sieve of Sundaram
        std::pair<int *, int> ret_primes2 = SieveSundaram(primes_upto);

        // Timer end point
        const auto t4 = std::chrono::high_resolution_clock::now();

        // Calculate performance time
        duration2 +=
            std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3)
                .count();

        // Print the primes found
        if (i == rep - 1) {
            PrintArray(ret_primes2.first, ret_primes2.second);
        }

        delete[] ret_primes2.first;
    }

    std::cout << "Sieve of Sundaram Performance Time: " << duration2 / rep
              << " microseconds.\n\n";  // Average duration

    // ========================================================================
    // 03. SIEVE OF ATKIN
    // ========================================================================

    PrintHeader(3);

    for (int i = 0; i < rep; i++) {
        // Timer start point
        const auto t5 = std::chrono::high_resolution_clock::now();

        // Explore primes using Sieve of Sundaram
        std::pair<int *, int> ret_primes3 = SieveAtkin(primes_upto);

        // Timer end point
        const auto t6 = std::chrono::high_resolution_clock::now();

        // Calculate performance time
        duration3 +=
            std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5)
                .count();

        // Print the primes found
        if (i == rep - 1) {
            PrintArray(ret_primes3.first, ret_primes3.second);
        }

        delete[] ret_primes3.first;
    }

    std::cout << "Sieve of Atkin Performance Time: " << duration3 / rep
              << " microseconds.\n\n";  // Average duration
}

// REFERENCE:
// https://www.researchgate.net/publication/333392383_The_Comparison_of_Methods_for_Generating_Prime_Numbers_between_The_Sieve_of_Eratosthenes_Atkins_and_Sundaram