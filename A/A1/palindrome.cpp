#include <iostream>
#include <string>
using namespace std;

int stringLength( string& str) {
    int length = 0;
    while (str[length] != '\0') length++;
    return length;
}

// Function to check if a given string is a palindrome
bool checkForPalindrome( string& str) {
    int startIdx = 0;
    int endIdx = stringLength(str) - 1;
    while (startIdx < endIdx) {
        if (str[startIdx] != str[endIdx]) return false;
        startIdx++;
        endIdx--;
    }
    return true;
}

int main() {
     string word;
     cout << "Enter: ";
     cin >> word;
    if (checkForPalindrome(word) == true)  cout << "Is a Palindrome";
    else  cout << "NOT a palindrome";
}
/*Time Complexity: (O(n)) for the entire program
Space Complexity: (O(1)) for the entire program*/