#include <iostream>
#include <vector>
using namespace std;

int BinarySrch (vector<int> arr , int target ) {
    int start = 0 , end = arr.size()-1 ;
    while (start <= end) {
        int mid = start+(end - start) / 2 ;
        if (arr[mid] > target) end = mid - 1 ;
        if (arr[mid] < target) start = mid + 1 ;
        else return (mid) ;
    }
    return -1 ;
}

int main () {
    vector<int> arr = { -1 , 0 , 2 , 5 , 7 , 9 , 11} ;
    int target = 5 ;
    cout << BinarySrch( arr , target ) ;
}