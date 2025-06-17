#include <iostream> 
using namespace std ;

struct Heap{
    int *arr ;
    int cap , size ;
    Heap(int cap) : cap(cap) , size(0) {
        arr = new int[cap] ;
    }

    void swap(int a, int b) {
        arr[a] = arr[a]+arr[b] - (arr[b]=arr[a]);
    }
    int parent(int i) { return (i-1)/2 ;}
    int left(int i) { return 2*i+1 ;}
    int right(int i) { return 2*i+2 ;}

    void insert(int val){
        if(size == cap) {
            cout << "Heap is FULL" ;
            return ;
        }
        arr[size] = val ;
        upheapify(size) ;
        size++ ;
    }

    void upheapify(int idx){
        while(idx != 0 && arr[parent(idx)] < arr[idx]){
            swap(idx , parent(idx)) ;
            idx = parent(idx) ;
        }
    }

    void getMax(){ cout << arr[0] << endl ;}

    void extractMax(){ 
        if (size == 0) return ;
        int max = arr[0] ;
        arr[0] = arr[size-1] ;
        size-- ;
        cout << max << endl ;
        downHeapify(0);
    }
    
    void downHeapify(int idx){
        int max = idx ;
        int l = left(idx) ;
        int r = right(idx) ;
        if(l < size && arr[l] > arr[max]) max = l ;
        if(r < size && arr[r] > arr[max]) max = r ;
        if(max != idx) {
            swap(idx , max) ;
            downHeapify(max) ;
        }
    }
    
    void incKey(int currVal , int newVal){
        for(int n = 0 ; n < size ; n++){
            if(arr[n] == currVal){
                arr[n] = newVal ;
                upheapify(n) ;
                break ;
            }
        }
    }

    void heapSort(){  while(size!=0) extractMax() ;  }
};

int main(){
    int arr[]={8,15,1,7,6,3,4,12,11,10,0} ;
    Heap heap(25) ;
    for(int nums : arr) heap.insert(nums) ;
    //heap.extractMax() ;
    heap.heapSort() ;
    
}