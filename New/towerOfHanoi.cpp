#include <iostream>
#include <string>
using namespace std;

void towerOfHanoi(int numDisc , string tower1 , string tower2 , string tower3 , int &steps){

    if(numDisc == 1) {
        cout << "Disc "<< numDisc << " " << tower1 << " --> " << tower3 <<endl ;
        steps++ ; 
        return ;
    }
    towerOfHanoi(numDisc - 1 , tower1 , tower3 , tower2, steps) ;
    cout << "Disc "<< numDisc << " " << tower1 << " --> " << tower3 << endl ;
    steps++ ;
    towerOfHanoi(numDisc - 1 , tower2 , tower1 , tower3, steps) ;
}

int main(){
    int steps = 0 ; 
    cout << "Enter the number of discs : " ;
    int numDisc ;
    cin >> numDisc ;
    towerOfHanoi(numDisc , "Tower1" , "Tower2" , "Tower3", steps);
    cout << "Total steps : " << steps << endl ; 

}