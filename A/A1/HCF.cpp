#include <iostream>
using namespace std;

int findGCD(int a, int b) {
    while(b!=0){
        int temp = b;
        b = a%b ;
        a=temp ;
    }
    return a ;
}
int main() {
    int a = 10, b = 15;
    cout << findGCD(a, b)<<endl ;
}  
//space:O(1)
//time:O(log(min(a,b)))