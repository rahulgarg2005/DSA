#include <iostream>
using namespace std;

int getMax(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

void countingSort(int arr[] , int n){
    int max = getMax(arr , n) ;
    int count[max+1] = {0} ;
    for(int i = 0 ; i < n ; i++) count[arr[i]]++ ;
    int idx = 0 ;
    for(int i = 0 ; i <= max ; i++){
        while(count[i]-- > 0) {
            arr[idx] = i ;
            idx++ ;
        }
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};

    countingSort(arr , 7);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
