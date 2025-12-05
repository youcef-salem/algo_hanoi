#include <iostream>
using namespace std;

#include "utilsHanoi.cpp"

/// HERE IS THE MAIN  ALGORITHM FOR THE ITERATIVE SOLUTION OF THE PROBLEM

int main(){
    //Initialization of the problem and user input
    Tower tower1("Tower 1"), tower2("Tower 2"), tower3("Tower 3");
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    initializeProblem(tower1,n);
    auto start = chrono::high_resolution_clock::now();//start timer
    long long steps= pow(2,n) -1; // the minimum number of steps needed for the solution

    if (n%2==0) //the loop in the case of an even number of disks
        for( long long i=1; i<=steps; i++){
            //printf("%d: ", i);
            int mod= i%3;
            if (mod==1) move(tower1,tower2);
            else if(mod==2) move(tower1,tower3);
            else move(tower2,tower3);
        }
    else //the loop in the case of an odd number of disks
        for(long long i=1; i<=steps; i++){
            //printf("%d: ", i);
            int mod= i%3;
            if(mod==1) move(tower1,tower3);
            else if(mod==2) move(tower1,tower2);
            else move(tower3,tower2);
        }
    auto end = chrono::high_resolution_clock::now();//end timer
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;
    return 0;
}
