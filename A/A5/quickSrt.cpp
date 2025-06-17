#include <iostream>
using namespace std ;

int partition(int array[] , int start , int end){
    int pivot = array[end] ;
    int i = start - 1;
    for(int j = start ; j < end ; j++){
        if(array[j] < pivot) {
            i++ ;
            array[j] = (array[j] + array[i]) - (array[i] = array[j]) ;
        }
    }
    i++ ;
    array[end] = (array[end] + array[i]) - (array[i] = array[end]) ;
    return i ;
}

void sort(int array[] , int start , int end){
    if(start < end) {
        int part = partition(array , start , end) ;
        sort(array , start , part - 1) ;
        sort(array , part + 1 , end) ;
    }
}

int main(){
    int array[] = {8,5,4,6,2,4,6,7,9,1,4,9,2,1,8} ;
    for(int nums : array) cout << nums << "," ;
    cout << endl ;
    sort(array , 0 , 15) ;
    for(int nums : array) cout << nums << "," ;
}