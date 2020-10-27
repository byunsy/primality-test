#include "tools.h"

#include <windows.h>

#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

void PrintHeader(int sieve) {
    // Print a simple line
    for (int i = 0; i < 80; i++) {
        std::cout << "=";
    }
    std::cout << "\n";

    // Print the header title
    switch (sieve) {
        case 1:
            std::cout << " 01. SIEVE OF ERATOSTHENES\n";
            break;
        case 2:
            std::cout << " 02. SIEVE OF SUNDARAM\n";
            break;
        case 3:
            std::cout << " 03. SIEVE OF ATKIN\n";
            break;
        default:
            break;
    }

    // Print another simple line
    for (int i = 0; i < 80; i++) {
        std::cout << "=";
    }
    std::cout << "\n\n";
}

void PrintArray(int *arr, int size) {
    // Set a maximum number to print out
    // - primes upto 10,000 is 1,229
    const int limit_primes = 1230;

    // Print all primes found if they are less than or equal to 1230
    if (size <= 1230) {
        for (int i = 0; i < size; i++) {
            // Set a width for each number
            std::cout << std::setw(7) << arr[i] << " ";

            // Print ten primes per line
            if ((i + 1) % 10 == 0) {
                std::cout << "\n";
            }
        }
        std::cout << "\n\nTotal number of elements: " << size << "\n\n";

        return;
    } else {
        // If the number gets too large to print, simply abbreviate using
        // the first three primes, ellipsis, and the last prime

        for (int i = 0; i < 3; i++) {
            std::cout << std::setw(7) << arr[i] << " ";
        }
        std::cout << std::setw(7) << "... ";
        std::cout << std::setw(7) << arr[size - 1]
                  << "\t     (List is too large to display here)\n";
        std::cout << "\nTotal number of elements: " << size << "\n\n";
    }
}

void ClearScreen(void) {
    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords,
                                    &count))
        return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount,
                                    homeCoords, &count))
        return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

// REFERENCE: https://www.cplusplus.com/articles/4z18T05o/