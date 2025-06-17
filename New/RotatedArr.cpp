#include <vector>
#include <iostream>
using namespace std ;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0 , end = nums.size()-1 ;
        while(start <= end){
            int mid = start + (end - start)/2 ;
            if(nums[mid] == target) return mid ;
            if(nums[start] == target) return start ;
            if(nums[end] == target) return end ;            
            else if(nums[start] < nums[mid]) {
                if(nums[start] <= target && target <= nums[mid]) end = mid-1;
                else start = mid + 1;
            }
            else{
                if(nums[mid] <= target && target<= nums[end]) start = mid + 1 ;
                else end = mid - 1 ;
            }
        }
        return -1 ;
    }
    
};
int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target;
    cout << "Enter target: ";
    cin >> target;
    Solution sol;
    int idx = sol.search(nums, target);
    if (idx != -1)
        cout << "Target found at index: " << idx << endl;
    else
        cout << "Target not found." << endl;
    return 0;
}