
#include <iostream>
using namespace std;
#include "hanoi_recursion.cpp"
#include <chrono>

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    
    auto start = chrono::high_resolution_clock::now();
    hanoi(n, 'A', 'C', 'B');
    auto end = chrono::high_resolution_clock::now();
    
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;
    
    return 0;
}