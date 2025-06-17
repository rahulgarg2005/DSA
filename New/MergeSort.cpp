#include <iostream>
using namespace std ;

void merge(int array[] , int start , int mid , int end , int comparisons = 0 , int swaps = 0){
    int* merged = new int[end - start + 1] ;
    int i = start , j = mid + 1 , k = 0 ;
    while(i <= mid && j <= end){
        comparisons++ ; 
        if(array[i] < array[j]){ 
            merged[k] = array[i] ;
            k++ ;
            i++ ;
        }
        else{
            merged[k] = array[j] ;
            k++ ; 
            j++ ; 
        }
    }
    while(i <= mid) {
        merged[k] = array[i] ;
        i++ ;
        k++ ;
    }
    while(j <= end) {
        merged[k] = array[j] ;
        k++ ;
        j++ ;
    }
    for(int i = start ; i <= end ; i++){
        array[i] = merged[i - start] ;
        swaps++ ;
    }
    delete[] merged ;

}

void divide(int array[] , int start , int end ){
    if (start >= end) return ;
    int mid = start + (end - start) / 2 ;
    divide(array , start , mid) ;
    divide(array , mid + 1 , end) ;
    merge(array , start , mid , end);
}

void mergeSort(int array[], int size) {
    divide(array, 0, size - 1);
}



int main(){
    int array[] = {2 , 5 , 1 , 0 , 7 , 9 , 11 , 3 , 8} ;
    for (int num : array) cout << num << " " ;
    cout << endl ;
    mergeSort(array , 9) ;
    for (int num : array) cout << num << " " ;
    

}