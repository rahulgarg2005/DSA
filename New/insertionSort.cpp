#include <iostream>
using namespace std ;

void insertionSort(int array[], int size){
    for(int i = 1 ; i < size ; i++){
        int key = array[i] ;
        int j = i - 1 ;
        while(j >=0 && array[j] > key){
            array[j+1] = array[j] ;
            j-- ;
        }
        array[j+1] = key ;
    }
}

int main() {
    int array[] = {2 , 4 , 3 , 7 , 9 , 11 , 34 , 9} ;
    for (int i : array) cout << i << " " ;
    insertionSort(array , 8) ;
    cout << endl ;
    for (int i : array) cout << i << " " ;

}
