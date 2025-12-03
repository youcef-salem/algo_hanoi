#include <iostream>
#include <stack> //used to win time (we already know how to make stacks)
#include <cmath>//used because why not


///HERE THERE ARE THE SUPLEMENTARY FUNCTIONS AND THE TOWER CLASS

using namespace std;
//It's basically just a stack but with a name attribute
class Tower {
public:
    string name;
    stack<int> s;

    Tower(const string& n) : name(n) {}
    bool empty() const {
        return s.empty();
    }
    int top() const {
        return s.top();
    }
    void push(int x) {
        s.push(x);
    }
    void pop() {
        s.pop();
    }
    int size(){
         return s.size();
    }
};
// The three towers whom the algorithm is centered around
Tower tower1("Tower 1"), tower2("Tower 2"), tower3("Tower 3");

//Put here as a function just to make the main function look cleaner
void initializeProblem(int n){
    for (int i=n; i>0;i--) tower1.push(i);
}
//Used for debugging. Left here just in case
void displayTower(Tower tower){
    int n= tower.size();
    while ( !tower.empty()){
        printf("%d\n",tower.top());
        tower.pop();
    }
}
//Moves the topmost disk from a tower to another tower and prints what happened
void moveDisk(Tower& first, Tower& second){
    if( first.empty() || (!second.empty() && (second.top() < first.top()))){ //case 1 if moving from disk first tower to the second is impossible then do the opposite
        printf("Disk %d from %s to %s\n", second.top(),second.name.c_str(), first.name.c_str());
        first.push(second.top());
        second.pop();
    } else { // case 2 move disk from first tower to second
        printf("Disk %d from %s to %s\n", first.top(),first.name.c_str(),second.name.c_str());
        second.push(first.top());
        first.pop();
    }
}

/// HERE IS THE MAIN SOLUTION ALGORITHM
int main()
{
    //Initialization of the problem and user input
    int n;
    printf("Enter the number of disks for the problem: ");
    scanf("%d", &n);
    initializeProblem(n);

    long long steps= pow(2,n) -1; // the minimum number of steps needed for the solution

    if (n%2==0) //the loop in the case of an even number of disks
        for(long long i=1; i<=steps; i++){
            printf("%d: ", i);
            if (i%3==1) moveDisk(tower1,tower2);
            else if(i%3==2) moveDisk(tower1,tower3);
            else moveDisk(tower2,tower3);
        }
    else //the loop in the case of an odd number of disks
        for(long long i=1; i<=steps; i++){
            printf("%d: ", i);
            if(i%3==1) moveDisk(tower1,tower3);
            else if(i%3==2) moveDisk(tower1,tower2);
            else moveDisk(tower3,tower2);
        }
    return 0;
}
