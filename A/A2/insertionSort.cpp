#include <iostream> 
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr){
    int comaparison = 0 , swap = 0 ;
    for(int i = 1 ; i < arr.size() ; i++){
        int key = arr[i] , j = i-1 ;
        while(j >=0 && arr[j] > key) {
            comaparison++ ;
            arr[j+1] = arr[j] ;
            swap++ ;
            j-- ;
        }
        if(j >= 0) comaparison++ ;
        arr[j+1] = key ;
        swap++ ;
    }
    cout << "Comparison:" << comaparison <<endl ;
    cout << "Swaps:" << swap <<endl ;
    
}
int main () {
    vector<int> arr = {5 , 4 , 3 , 8 , 9 , 7 , 1 , 6 } ;
    insertionSort(arr) ;
    for(int num : arr) cout << num << " " ;
}   