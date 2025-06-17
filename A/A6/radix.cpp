#include <iostream>
using namespace std;

int getMax(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int size, int pos) {
    int output[size];
    int count[10] = {0};

    for(int i = 0; i < size; i++) count[(arr[i] / pos) % 10]++;

    for(int i = 1; i < 10; i++) count[i] += count[i - 1];

    for(int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / pos) % 10 ;
        output[count[digit] - 1] = arr[i] ;
        count[digit]--;
    }
    for(int i = 0; i < size; i++) arr[i] = output[i];
}

void radixSort(int arr[], int size) {
    int max = getMax(arr, size);
    for(int position = 1; max / position > 0; position *= 10) countingSort(arr, size, position);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66} ;
    int size = sizeof(arr) / sizeof(arr[0]) ;
    radixSort(arr, size);

    cout << "Sorted array: ";
    for(int i = 0; i < size; i++) cout << arr[i] << " " ;
    cout << endl;

}
