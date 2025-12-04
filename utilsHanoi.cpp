
#include <iostream>
using namespace std;
#include <stack> //used to win time (we already know how to make stacks)
#include <cmath>//used because why not
#include <chrono>// to count time

///THIS FILE CONTAINS THE CODE FOR THE UTILITY FUNCTIONS THAT ARENT VERY IMPORTANT

//The tower class (It's basically just a stack but with a name attribute)
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

//To fill the first tower with disks at the start
void initializeProblem(Tower& tower, int n){
    for (int i=n; i>0;i--) tower.push(i);
}
//Displays Tower content (used for debugging)
void displayTower(Tower tower){
    int n= tower.size();
    while ( !tower.empty()){
        printf("%d\n",tower.top());
        tower.pop();
    }
}
//moves the topmost disk from a tower to another and prints the movements
void moveDisk(Tower& first, Tower& second){
       //printf("Disk %d from %s to %s\n", first.top(),first.name.c_str(),second.name.c_str());
        second.push(first.top());
        first.pop();
}
//Moves the topmost disk from a tower to another tower and prints what happened
void move(Tower& first, Tower& second){
    if( first.empty() || (!second.empty() && (second.top() < first.top()))){ //if moving a disk from first to second is impossible then do the opposite
        moveDisk(second, first);
    } else { //move disk from first  to second
        moveDisk(first, second);
    }
}
