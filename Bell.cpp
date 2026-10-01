#include "Bell.h"
#include <iostream>

Bell::Bell() : nextIsDing(true) {}

void Bell::sound() {
    std::cout << (nextIsDing ? "ding" : "dong") << std::endl;
    nextIsDing = !nextIsDing;
}