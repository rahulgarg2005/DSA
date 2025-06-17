#include <iostream>
using namespace std ;

struct Heap{
    int* array ;
    int capacity ; 
    int size ;
    Heap(int capacity) : capacity(capacity) , size(0) {
        array = new int[capacity] ;
    }

    void swap(int first , int second){
        int temp = array[first] ;
        array[first] = array[second] ;
        array[second] = temp ;
    }
    int parent(int i) {
        return (i-1)/2 ;
    }
    int left(int i) {
        return 2*i+1 ;
    }
    int right(int i) {
        return 2*i+2 ;
    }
    void insert(int val){ 
        if(size == capacity) return ;
        array[size] = val ;
        upheapify(size) ;
        size++ ;
    }
    void upheapify(int idx){
        while(idx != 0 && array[parent(idx)] > array[idx]){
            swap(idx , parent(idx)) ;
            idx = parent(idx) ;
        }
    }
    void printHeap(){
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return ;
        }
        for(int i = 0 ; i < size ; i++) cout << array[i] << "->" ;
        cout << endl ;
    }
    int remove(){
        if(size == 0) return -1;
        int temp = array[0] ;
        array[0] = array[size-1] ;
        size-- ;
        downheapify(0) ;
        return temp ;
    }
    void downheapify(int idx){
        int lft = left(idx) ;
        int rght = right(idx) ;
        int min = idx ;
        if(lft < size && array[lft] < array[min]) min = lft ;
        if(rght < size && array[rght] < array[min]) min = rght ;
        if(min != idx){
            swap(min , idx) ;
            downheapify(min) ;
        }
    }
    void HeapSort() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return ;
        }
        while(size != 0)  cout << remove() << " " ;
    }
};

int main(){
    Heap heap(10) ; 
    int arr[]={4, 10, 13, 5, 7, 9, 8} ;
    for(int nums : arr) heap.insert(nums) ;
    heap.printHeap() ;
    heap.HeapSort() ;

}