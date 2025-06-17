#include <iostream>
#include <vector>
#include <string>
using namespace std ;

class trie{
public:
    class Node{
    public:
        vector<Node*> children ;
        bool end ;
        Node() {
            children = vector<Node*>(26 , nullptr) ;
            end = false ;
        }
    };

    Node* root ;
    trie(){
        root = new Node() ;
    }

    void insert(const string &word){
        Node* curr = root ;
        for(char c : word){
            int idx = c - 'a' ;
            if(curr -> children[idx] == nullptr) curr -> children[idx] = new Node() ;
            curr = curr -> children[idx] ;
        }
        curr -> end = true ;
    }

    bool search(const string &key){
        Node* curr = root ;
        for(char c : key) {
            int idx = c - 'a' ;
            if(curr -> children[idx] == nullptr) return false ;
            curr = curr -> children[idx] ;
        }
        return curr -> end ;
    }
};

int main() {
    trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("mango");
    trie.insert("man");
    trie.insert("woman");

    // Search for words in the Trie
    cout << boolalpha;
    cout << trie.search("apple") << endl;  // Output: true
    cout << trie.search("app") << endl;    // Output: true
    cout << trie.search("mango") << endl;  // Output: true
    cout << trie.search("man") << endl;    // Output: true
    cout << trie.search("woman") << endl;  // Output: true
    cout << trie.search("wom") << endl;    // Output: false
    cout << trie.search("banana") << endl; // Output: false
}
