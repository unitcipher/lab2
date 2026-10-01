#include "OddEvenSeparator.h"
#include <iostream>

void OddEvenSeparator::add_number(int n) { numbers.push_back(n); }

void OddEvenSeparator::even() const {
    bool first = true;
    for (int n : numbers)
        if (n % 2 == 0) { if (!first) std::cout << " "; std::cout << n; first = false; }
    std::cout << std::endl;
}

void OddEvenSeparator::odd() const {
    bool first = true;
    for (int n : numbers)
        if (n % 2 != 0) { if (!first) std::cout << " "; std::cout << n; first = false; }
    std::cout << std::endl;
}