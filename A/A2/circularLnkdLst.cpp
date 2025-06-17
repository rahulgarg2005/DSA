#include <iostream>
using namespace std;

// Class to represent a circular linked list
class Ques3 {
public:
    // Constructor to initialize the linked list
    Ques3() : head(nullptr){}
    

    // Nested class to represent a node in the circular linked list
    struct Node{
        int val;
        Node* next;
        Node(int val): val(val) , next(nullptr) {} 
    }; 

    Node* head; // Pointer to the head of the linked list
    int size = 0; // Size of the linked list

    // Function to add a node with value 'val' at the end of the list
    void addToLast(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            size++;
            return;
        }
        Node* currNode = head;
        while (currNode->next != head) currNode = currNode->next;
        currNode->next = newNode;
        newNode->next = head;
        size++;
    }

    // Function to add a node with value 'val' at the beginning of the list
    void addAtFirst(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            size++;
            return;
        }
        Node* currNode = head;
        while (currNode->next != head) currNode = currNode->next;
        currNode->next = newNode;
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Function to print the list up to the k-th node
    void printTill_kth(int k) {
        if (size < k || k < 0) {
            cout << "Wrong 'k'" << endl;
            return;
        }
        if (head == nullptr) return;
        Node* curr = head;
        int a = 0;
        while (a < k) {
            cout << curr->val << " -> ";
            curr = curr->next;
            a++;
        }
        cout << "HEAD" << endl;
    }

    // Function to print the list starting from the k-th node
    void printFrom_kthTo(int k) {
        if (size < k || k < 0) {
            cout << "Wrong 'k'" << endl;
            return;
        }
        if (head == nullptr) return;
        Node* curr = head;
        int a = 0;
        while (a < k - 1) {
            curr = curr->next;
            a++;
        }

        Node* start = curr;
        while (curr->next != start) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << curr->val << " -> ";
        cout << "HEAD" << endl;
    }
    
};

int main() {
    Ques3 cll;
    cll.addToLast(1); // Add 1 to the end of the list
    cll.addToLast(2); // Add 2 to the end of the list
    cll.addToLast(3); // Add 3 to the end of the list
    cll.addToLast(4); // Add 4 to the end of the list
    cll.addToLast(5); // Add 5 to the end of the list
    cll.addToLast(6); // Add 6 to the end of the list
    cll.addToLast(7); // Add 7 to the end of the list
    cll.addToLast(8); // Add 8 to the end of the list
    cll.addToLast(9); // Add 9 to the end of the list
    cll.addToLast(10); // Add 10 to the end of the list
    cll.addToLast(11); // Add 11 to the end of the list
    cll.addToLast(12); // Add 12 to the end of the list
    cll.addToLast(13); // Add 13 to the end of the list
    cll.addToLast(14); // Add 14 to the end of the list
    cll.printFrom_kthTo(4); // Print the list starting from the 4th node

    return 0;
}