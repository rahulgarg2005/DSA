#include <iostream>
using namespace std ;

struct minHeap{
    int *arr ;
    int cap , size ;
    minHeap(int cap) : cap(cap) , size(0) {
        arr = new int[cap] ;
    }

    void swap(int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    int parent(int i) { return (i-1)/2 ;}
    int left(int i) { return 2*i+1 ;}
    int right(int i) { return 2*i+2 ;}

    void insert(int val){
        if(size == cap) return ;
        arr[size] = val ;
        upheapify(size) ;
        size++ ;
    }

    void upheapify(int idx){
        while(idx != 0 && arr[parent(idx)] > arr[idx]){
            swap(idx , parent(idx)) ;
            idx = parent(idx) ;
        }
    }

    void extractMin(){ 
        if (size == 0) return ;
        int min = arr[0] ;
        arr[0] = arr[size-1] ;
        size-- ;
        cout << min << endl ;
        downHeapify(0);
    }
    
    void downHeapify(int idx){
        int min = idx ;
        int l = left(idx) ;
        int r = right(idx) ;
        if(l < size && arr[l] < arr[min]) min = l ;
        if(r < size && arr[r] < arr[min]) min = r ;
        if(min != idx) {
            swap(idx , min) ;
            downHeapify(min) ;
        }
    }
};
int main(){
    int arr1 []= {1 , 2 , 5 , 8 , 9 , 11 , 14 , 17 , 22} ;
    int arr2 []= {0 , 3 , 5 , 6 , 13 , 22 , 23} ;
    int arr3 []= {4 , 9} ;
    minHeap heap(50) ;
    for(int nums : arr1) heap.insert(nums) ;
    for(int nums : arr2) heap.insert(nums) ;
    for(int nums : arr3) heap.insert(nums) ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;
    heap.extractMin() ;

}
