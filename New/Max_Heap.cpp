#include <iostream>
using namespace std;

struct Heap {
    int* array;
    int capacity;
    int size;
    Heap(int capacity) : capacity(capacity), size(0) {
        array = new int[capacity];
    }

    void swap(int first, int second) {
        array[first] = array[first] + array[second] - (array[second] = array[first]);
    }
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; } 
    void insert(int val) {
        if (size == capacity) return;
        array[size] = val;
        upheapify(size);
        size++;
    }
    void upheapify(int idx) {
        while (idx != 0 && array[parent(idx)] < array[idx]) { // Changed '>' to '<'
            swap(idx, parent(idx));
            idx = parent(idx);
        }
    }
    void printHeap() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        for (int i = 0; i < size-1; i++) cout << array[i] << "->";
        cout << array[size-1] << endl;
    }
    int remove() {
        if (size == 0) return -1;
        int temp = array[0];
        array[0] = array[size - 1];
        size--;
        downheapify(0);
        return temp;
    }
    void downheapify(int idx) {
        int lft = left(idx);
        int rght = right(idx);
        int max = idx; // Changed 'min' to 'max'
        if (lft < size && array[lft] > array[max]) max = lft; // Changed '<' to '>'
        if (rght < size && array[rght] > array[max]) max = rght; // Changed '<' to '>'
        if (max != idx) {
            swap(max, idx);
            downheapify(max);
        }
    }
    void HeapSort() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        while (size != 0) cout << remove() << " ";
    }
};

int main() {
    Heap heap(100);
    int arr[] = {4, 10, 13, 5, 7, 9, 8 , 1 , 2 , 3 , 6 , 11 , 12};
    for (int nums : arr) heap.insert(nums);
    for(int nums : arr) cout << nums << "," ;
    cout<<endl ;
    cout << "Heap : " ;
    heap.printHeap();
    // cout << "Heap Sort: " ;
    // heap.HeapSort() ;
    // cout << endl ;
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    heap.remove();
    cout << "Heap : " ;
    heap.printHeap();
    
    
}