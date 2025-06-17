#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr){
    for(int i = 0 ; i < arr.size() ; i++){
        int min  = i ;
        for(int j = i+1 ; j < arr.size() ; j++){
            if (arr[min] > arr[j]) min = j ;
        }
        if(min != i) {
            arr[i] = arr[min] ^ arr[i] ;
            arr[min] = arr[min] ^ arr[i] ;
            arr[i] = arr[min] ^ arr[i] ;
        }
    }
}

int main () {
    vector<int> arr = {7 , 1 , 4 , 6 , 0 , -1} ;
    for(int nums : arr) cout << nums << " " ;
    selectionSort(arr) ;
    cout << "\n" ;
    for(int nums : arr) cout << nums << " " ;
    
}