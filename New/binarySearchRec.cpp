#include <iostream>
#include <vector>
using namespace std ;

int binSrch ( vector<int> arr , int target , int start , int end ) {
    int mid = start + (end - start)/2;
    if (arr[mid] == target) return mid ;

    if (arr[mid] > target) binSrch(arr , target , start , mid - 1) ;
    if (arr[mid] < target) binSrch(arr , target , mid + 1 , end) ;
    
}

int main () {
    vector<int> arr = { -1 , 0 , 2 , 5 , 7 , 9 , 11} ;
    int target = 5 ;
    cout << binSrch( arr , target , 0 , 6) ;
}