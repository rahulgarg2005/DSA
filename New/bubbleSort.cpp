#include <iostream>
using namespace std ;

void sort(int arr[] , int size){
    for(int i = 0 ; i < size - 1 ; i++){
        for(int j = size - 1 ; j >i  ; j--){
            if(arr[j] < arr[j-1]) arr[j - 1] = (arr[j] + arr[j - 1]) - (arr[j] = arr[j - 1]) ;

        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    sort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}