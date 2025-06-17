#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0 , bestBuy = prices[0] ;
        for (int  i = 0 ; i < prices.size() ; i++){
			max = max(max, prices[i] - bestBuy) ;
		}
    }
};