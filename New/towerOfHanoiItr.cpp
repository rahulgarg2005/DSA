#include <bits/stdc++.h>
using namespace std;

char rod[] = {'S', 'A', 'D'};
vector<stack<int>> stacks(3);

void moveDisk(int src, int des){
    if (stacks[des].empty() || (!stacks[src].empty() && stacks[src].top() < stacks[des].top())){
        cout << "Move disk " << stacks[src].top() << " from rod " << rod[src] << " to rod " << rod[des] << "\n";
        stacks[des].push(stacks[src].top());
        stacks[src].pop();
    }
    else moveDisk(des, src);
}

void towerOfHanoi(int n){
    int src = 0, helper = 1, dest = 2;
    for (int i = n; i > 0; i--)
        stacks[src].push(i);

    int totalMoves = static_cast<int>(pow(2, n)) - 1;
    if (n % 2 == 0) swap(helper, dest);
    for (int i = 1; i <= totalMoves; i++){
        if (i % 3 == 0) moveDisk(helper, dest);
        else if (i % 3 == 1) moveDisk(src, dest);
        else moveDisk(src, helper);
    }
}

int main()
{
    int n = 4; // number of disks
    towerOfHanoi(n);
}