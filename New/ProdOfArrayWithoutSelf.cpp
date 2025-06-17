#include <iostream>
#include <vector>
using namespace std;

vector<int> product ( vector <int> nums ) {
    int n = nums.size() ;
    vector<int> answer( n , 1 ) ;
    vector<int> prefix ( n , 1 );
    vector<int> suffix (n , 1);
    for (int i = 1 ; i < n ; i++) prefix[i] = prefix[i-1] * nums[i-1] ;
    for (int i = n-2 ; i >=0 ; i-- ) suffix[i] = suffix[i+1] * nums[i+1] ;
    for (int i = 0 ; i < n ; i++) answer[i] = prefix[i] * suffix[i] ;
    return answer ;

}
int main () {
    vector <int> nums = { 1 , 2 , 3 , 4 , 5} ;
    vector<int> ans = product( nums ) ;
    for (int i : ans ) cout << i << " "  ;
}