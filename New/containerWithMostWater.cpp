#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> height){
    int leftPointer = 0 , rightPointer = height.size() - 1 , maxArea = 0;
    while ( leftPointer < rightPointer) {
        int width = rightPointer - leftPointer;
        int length = min(height[leftPointer], height[rightPointer]);
        int currArea = width * length;
        maxArea = max(maxArea, currArea);
        if (height[leftPointer] < height[rightPointer]) leftPointer++;
        else rightPointer--;
    }
    return maxArea;
}

int main () {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    
}