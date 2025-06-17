#include <iostream>
#include <string>

using namespace std;

// Function to split a sentence (vector of chars) into words (vector of vector of chars)
void split(char sentence []) {
    string word;  // Vector to store the current word

    // Iterate through each character in the sentence
    for (int i=0; sentence[i] !='\0'; i++) {
        if (sentence[i] == ' ') {
            cout << word << "\n" ;
            word="";  // Clear the word vector for the next word
        } else word+=sentence[i] ;  // Add the character to the current word
        
    }
    cout << word << "\n" ;
}

int main() {
    // Define a sentence as a vector of characters
    char sentence [] = {'H', 'e', 'l', 'l', 'o', ' ', 'R', 'a', 'h', 'u', 'l', ' ', 'h', 'o', 'w', ' ', 'a', 'r', 'e', ' ', 'y', 'o', 'u', '\0'} ;
    
    // Split the sentence into words
    split(sentence);
} 
/*Time Complexity: (O(n)) for the entire program
Space Complexity: (O(n)) for the entire program*/ 