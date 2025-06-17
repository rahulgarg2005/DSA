#include <iostream>
using namespace std;

void merge(int array[], int start, int mid, int end, int& comparisons, int& swaps) {
    int* merged = new int[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        comparisons++;
        if (array[i] < array[j]) {
            merged[k] = array[i];
            k++; 
            i++;
        } else {
            merged[k] = array[j];
            k++;
            j++;
        }
    } 

    while (i <= mid) {
        merged[k] = array[i];
        i++;
        k++;
    }
 
    while (j <= end) {
        merged[k] = array[j];
        k++;
        j++;
    }

    for (int i = start; i <= end; i++) {
        array[i] = merged[i - start];
        swaps++; // Count the number of assignments back to the original array
    }

    delete[] merged;
}

void divide(int array[], int start, int end, int& comparisons, int& swaps) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    divide(array, start, mid, comparisons, swaps);
    divide(array, mid + 1, end, comparisons, swaps);
    merge(array, start, mid, end, comparisons, swaps);
}

void mergeSort(int array[], int size, int& comparisons, int& swaps) {
    divide(array, 0, size - 1, comparisons, swaps);
}

int main() {
    int array[] = {2, 5, 1, 0, 7, 9, 11, 3, 8};
    int comparisons = 0, swaps = 0;

    cout << "Original array: ";
    for (int num : array) cout << num << " ";
    cout << endl;

    mergeSort(array, 9, comparisons, swaps);

    cout << "Sorted array: ";
    for (int num : array) cout << num << " ";
    cout << endl;

    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl; // Renamed "Swaps" to "Assignments"

}