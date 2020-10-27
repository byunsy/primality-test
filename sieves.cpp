#include "sieves.h"

#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>

/* ----------------------------------------------------------------------------
PROCEDURE:
    SieveEratosthenes
PARAMETERS:
    num, an integer >= 2
PURPOSE:
    Finds all primes less than or equal to num
PRODUCES:
    primes, a pointer to an array with primes less than or equal to num
    counter, size of the array containing all the primes found
---------------------------------------------------------------------------- */
std::pair<int *, int> SieveEratosthenes(int num) {
    // Set maximum array size to hold all the primes found
    const int arr_length = 665000;

    // Create a dynamically allocated array for k values
    bool *candidates = new bool[num + 1];

    // Initialize all elements to 'true' value
    std::fill_n(candidates, num + 1, 1);

    // Sieve of Eratosthenes
    for (int i = 2; i <= sqrt(num); i++) {
        if (candidates[i] == true) {
            for (int j = i * i; j <= num; j += i) {
                candidates[j] = false;
            }
        }
    }

    // Create an array that will hold the primes found above
    int *primes = new int[arr_length];
    int counter = 0;

    for (int i = 2; i <= num; i++) {
        if (candidates[i] == true) {
            primes[counter] = i;
            counter++;
        }
    }

    // Delete all dynamically allocated arrays on heap
    delete[] candidates;

    return std::make_pair(primes, counter);
}

/* ----------------------------------------------------------------------------
PROCEDURE:
    SieveSundaram
PARAMETERS:
    num, an integer >= 2
PURPOSE:
    Finds all primes less than or equal to num
PRODUCES:
    primes, a pointer to an array with primes less than or equal to num
    counter, size of the array containing all the primes found
---------------------------------------------------------------------------- */
std::pair<int *, int> SieveSundaram(int num) {
    // Set maximum array size to hold all the primes found
    const int arr_length = 665000;

    // First find (n-2/2) and let it be k
    int k = (num - 2) / 2;

    // Create a dynamically allocated array for k values
    bool *candidates = new bool[k + 1];

    // Initialize all elements to 'true' value
    std::fill_n(candidates, k + 1, 1);

    // Sieve of Sundaram
    for (int i = 1; (2 * i + 2 * i * i) <= k; i++) {
        for (int j = i; (i + j + 2 * i * j) <= k; j++) {
            candidates[i + j + 2 * i * j] = false;
        }
    }

    // Create an array that will hold the primes found above
    int *primes = new int[arr_length];

    // 2 is always included as the first prime
    primes[0] = 2;
    int counter = 1;

    for (int i = 1; i <= k; i++) {
        if (candidates[i] == true) {
            primes[counter] = 2 * i + 1;
            counter++;
        }
    }

    // Delete all dynamically allocated arrays on heap
    delete[] candidates;

    return std::make_pair(primes, counter);
}
/* ----------------------------------------------------------------------------
PROCEDURE:
    SieveAtkin
PARAMETERS:
    num, an integer >= 2
PURPOSE:
    Finds all primes less than or equal to num
PRODUCES:
    primes, a pointer to an array with primes less than or equal to num
    counter, size of the array containing all the primes found
---------------------------------------------------------------------------- */
std::pair<int *, int> SieveAtkin(int num) {
    // Set maximum array size to hold all the primes found
    const int arr_length = 665000;

    // Create a dynamically allocated array for k values
    bool *candidates = new bool[num + 1];

    // Initialize all elements to 'true' value
    std::fill_n(candidates, num + 1, 0);

    // Sieve of Atkin
    for (int x = 1; x * x < num; x++) {
        for (int y = 1; y * y < num; y++) {
            // Main part of Sieve of Atkin
            // Step 1
            int n = (4 * x * x) + (y * y);
            if (n <= num && (n % 12 == 1 || n % 12 == 5)) {
                candidates[n] = !candidates[n];
            }
            // Step 2
            n = (3 * x * x) + (y * y);
            if (n <= num && n % 12 == 7) {
                candidates[n] = !candidates[n];
            }
            // Step 3
            n = (3 * x * x) - (y * y);
            if (x > y && n <= num && n % 12 == 11) {
                candidates[n] = !candidates[n];
            }
        }
    }
    // Mark all multiples of squares as non-prime
    for (int r = 5; r * r < num; r++) {
        if (candidates[r]) {
            for (int i = r * r; i < num; i += r * r) {
                candidates[i] = false;
            }
        }
    }

    // Create an array that will hold the primes found above
    int *primes = new int[arr_length];

    // 2 and 3 are included as the first two primes
    primes[0] = 2;
    primes[1] = 3;
    int counter = 2;

    for (int i = 1; i <= num; i++) {
        if (candidates[i] == true) {
            primes[counter] = i;
            counter++;
        }
    }

    // Delete all dynamically allocated arrays on heap
    delete[] candidates;

    return std::make_pair(primes, counter);
}