#include <iostream>
using namespace std;

struct BucketSort {
    int numBuckets;
    BucketSort(int buckets) : numBuckets(buckets) {}

    void insertionSort(float bucket[], int size) {
        for (int i = 1; i < size; i++) {
            float key = bucket[i];
            int j = i - 1;
            while (j >= 0 && bucket[j] > key) {
                bucket[j + 1] = bucket[j];
                j--;
            }
            bucket[j + 1] = key;
        }
    }

    void bucketSort(float arr[], int n) {
        // Step 1: Create buckets
        float buckets[numBuckets][10];     
        int bucketSizes[10] = {0};         

        // Step 2: Distribute into buckets
        for (int i = 0; i < n; i++) {
            int idx = int(arr[i] * numBuckets); // bucket index (0 ≤ idx < numBuckets)
            if (idx >= numBuckets) idx = numBuckets - 1; // guard upper bound
            int &size = bucketSizes[idx];
            if (size < 10) {
                buckets[idx][size++] = arr[i];
            }
        }

        for (int i = 0; i < numBuckets; i++) {
            if (bucketSizes[i] > 0) insertionSort(buckets[i], bucketSizes[i]);
        }

        int index = 0;
        for (int i = 0; i < numBuckets; i++) {
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    void printArray(float arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << ",";
        cout << endl;
    }
};

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    BucketSort bs(6);  // 6 buckets

    cout << "Original array: ";
    bs.printArray(arr, n);

    bs.bucketSort(arr, n);

    cout << "Sorted array: ";
    bs.printArray(arr, n);

    return 0;
}
