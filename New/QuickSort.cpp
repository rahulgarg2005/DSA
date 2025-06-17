#include <iostream>
using namespace std ;

int partition(int array[] , int start , int end){
    int pivot = array[end] ;
    int i = start - 1 ;
    for(int j = start ; j < end ; j++){//0-7
        if(array[j] < pivot) {// 8 5 4 2 3 6 1 0 
            i++ ;
            array[i] = (array[j] + array[i]) - (array[j] = array[i]) ;//swap i and j
        }
    }
    i++ ;
    array[i] = (array[end] + array[i]) - (array[end] = array[i]) ;
    return i ;
}// 0 5 4 2 3 6 1 8

void sort(int array[] , int start , int end) {
    if(start < end){
        int Part = partition(array , start , end);

        sort(array , start , Part - 1) ;
        sort(array , Part + 1 , end) ;
    }
}

int main(){
    int array[] = {2 , 5 , 1 , 0 , 7 , 9 , 11 , 3 , 8} ;
    for (int num : array) cout << num << " " ;
    cout << endl ;
    sort(array , 0 , 8) ;
    for (int num : array) cout << num << " " ;

}