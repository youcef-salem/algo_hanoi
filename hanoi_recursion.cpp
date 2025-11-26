#include <iostream>
using namespace std;
void move(char from, char to) {
   
    cout << "Move disk "  << " from " << from << " to " << to << endl;
}

void hanoi(int n, char a, char c, char b) {
    if (n != 0) {
        hanoi(n - 1, a, b, c);
        move(a, c);
        hanoi(n - 1, b, c, a);
    }
}

