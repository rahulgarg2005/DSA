#include <iostream>
using namespace std;

// Class to represent a doubly linked list
class Ques2 {
public:
    // Constructor to initialize the linked list
    Ques2(): head (nullptr) , size (0) {}

    // Nested class to represent a node in the doubly linked list
    struct Node{
        int val;
        Node* next,*prev;
        Node(int val): val(val) , next(nullptr) , prev(nullptr){} 
    };

    Node* head; // Pointer to the head of the linked list
    int size; // Size of the linked list

    // Function to add a node with value 'val' at the beginning of the list
    void addAtFirst(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++;
    }

    // Function to add a node with value 'val' at the end of the list
    void addAtLast(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }
        Node* lastNode = head;
        while (lastNode->next != nullptr) lastNode = lastNode->next;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        size++;
    }

    // Function to add a node with value 'val' at the k-th position in the list
    void addAt_kth(int val, int k) {
        if (k > size) {
            cout << "Wrong k" << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (k == 0) {
            addAtFirst(val);
            return;
        }
        Node* current = head;
        for (int i = 0; i < k - 1; i++) current = current->next;
        newNode->next = current->next;
        if (current->next != nullptr) current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
        size++;
    }

    // Function to delete the node at the k-th position in the list
    void del_kth(int k) {
        if (k >= size) {
            cout << "Wrong k" << endl;
            return;
        }
        if (k == 0) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            size--;
            return;
        }
        Node* currNode = head;
        for (int i = 0; i < k - 1; i++) currNode = currNode->next;
        Node* nodeToDelete = currNode->next;
        currNode->next = nodeToDelete->next;
        if (nodeToDelete->next != nullptr) nodeToDelete->next->prev = currNode;
        delete nodeToDelete;
        size--;
    }

    // Function to print the linked list
    void printList() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->val << " <-> ";
            currNode = currNode->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Ques2 doubly;
    doubly.addAtFirst(1); // Add 1 to the beginning of the list
    doubly.addAtFirst(2); // Add 2 to the beginning of the list
    doubly.addAtFirst(3); // Add 3 to the beginning of the list
    doubly.addAtFirst(4); // Add 4 to the beginning of the list
    doubly.addAtLast(5); // Add 5 to the end of the list
    doubly.printList(); // Print the list
    doubly.addAt_kth(7, 3); // Add 7 at the 3rd position in the list
    doubly.printList(); // Print the list
    doubly.del_kth(3); // Delete the node at the 3rd position in the list
    doubly.printList(); // Print the list
}