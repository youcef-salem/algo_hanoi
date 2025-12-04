
#include <iostream>
using namespace std;

#include "hanoi_recursion.cpp"

/// HERE IS THE MAIN ALGORITHM FOR THE RECURSIVE SOLUTION OF THE PROBLEM

int main() {
    int n;
    Tower A("A") ,B("B") ,C("C") ;
    cout << "Enter number of disks: ";
    cin >> n;
    initializeProblem(A,n);

    auto start = chrono::high_resolution_clock::now();
    hanoi(n, A, C, B);
    auto end = chrono::high_resolution_clock::now();

   auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;

    return 0;
}
