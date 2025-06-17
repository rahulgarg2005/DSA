#include <iostream>
using namespace std;

void generateFibonacci(int n){
    int first = 0 , second = 1;

    if(n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return;
    }

    cout << "Fibonacci sequence up to " << n << " terms:" << endl;

    for(int i = 1; i <= n; i++){
        cout << first << " ";
        int next = first + second;
        first = second;
        second = next;
    }
}
int main (){
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    generateFibonacci(n);
}
/*Time Complexity: (O(n))
Space Complexity: (O(1))*/  