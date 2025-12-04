#include <iostream>
#include "utilsHanoi.cpp"

///THIS FILE ONLY CONTAINS THE CODE FOR THE RECURSIVE FUNCTION

void hanoi(int n, Tower& a, Tower& c, Tower& b) {
    if (n != 0) {
        hanoi(n - 1, a, b, c);
        move(a, c);
        hanoi(n - 1, b, c, a);
    }
}

