#include <iostream>
#include <vector>
using namespace std;

// Function to check if it is possible to allocate books such that no student reads more than maxAllowedPages
bool isValid(vector<int> arr, int n, int m, int maxAllowedPages) {
    int students = 1, pages = 0;
    // Loop through each book
    for (int i = 0; i < n; i++) { // Time complexity: O(n)
        // If a single book has more pages than maxAllowedPages, return false
        if (arr[i] > maxAllowedPages) return false;
        // If adding this book to the current student's allocation doesn't exceed maxAllowedPages
        else if (pages + arr[i] <= maxAllowedPages) pages += arr[i];
        // Otherwise, allocate this book to the next student
        else {
            students++;
            pages = arr[i];
        }
    }
    // Return true if the number of students required is less than or equal to m
    return students > m ? false : true ;
}

// Function to find the minimum number of pages that can be allocated to a student
int allocateBooks(vector<int> arr, int n, int m) {
    // If there are more students than books, return -1
    if (m > n) return -1; 
    
    int sum = 0;
    // Calculate the total number of pages
    for (int i = 0; i < arr.size(); i++) sum += arr[i]; // Time complexity: O(n)
    
    int start = 0, end = sum, ans = -1;
    // Binary search to find the minimum number of pages
    while (start <= end) { // Time complexity: O(log(sum))
        int mid = start + (end - start) / 2;
        // Check if it is possible to allocate books with mid as the maximum number of pages
        if (isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2;

    // Print the minimum number of pages that can be allocated to a student
    cout << allocateBooks(arr, n, m) << endl;

    return 0;
}