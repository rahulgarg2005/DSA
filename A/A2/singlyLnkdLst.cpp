#include <iostream>
using namespace std;

// Class to represent a singly linked list
class Ques1 {
public:
    // Constructor to initialize the linked list
    Ques1() : head(nullptr) , size(0) {}

    // Nested class to represent a node in the linked list
    struct Node{
        int val;
        Node* next;
        Node(int val): val(val) , next(nullptr) {} 
    };

    Node* head; // Pointer to the head of the linked list
    int size; // Size of the linked list

    // Function to add a node with value 'val' at the end of the list
    void addToLast(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }
        Node* currNode = head;
        while (currNode->next != nullptr) currNode = currNode->next;
        currNode->next = newNode;
        size++;
    }

    // Function to add a node with value 'val' at the beginning of the list
    void addToFirst(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Function to add a node with value 'val' at the k-th position in the list
    void addTo_kth(int val, int k) {
        if (k > size) {
            cout << "Wrong k" << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (k == 0) {
            newNode->next = head;
            head = newNode;
            size++;
            return;
        }

        Node* prevNode = head;
        for (int j = 0; j < k - 1; j++) prevNode = prevNode->next;

        newNode->next = prevNode->next;
        prevNode->next = newNode;
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
            size--;
            return;
        }
        Node* prev = head;
        for (int i = 0; i < k - 1; i++) prev = prev->next;
        prev->next = prev->next->next;
        size--;
    }

    // Function to print the linked list
    void printList() {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->val << "->";
            current = current->next;
        }
        cout << "Null" << endl;
    }
};

int main() {
    Ques1 store;
    store.addToLast(1); // Add 1 to the end of the list
    store.addToLast(2); // Add 2 to the end of the list
    store.addToLast(3); // Add 3 to the end of the list
    store.addToLast(4); // Add 4 to the end of the list
    store.addToLast(5); // Add 5 to the end of the list
    store.addToFirst(0); // Add 0 to the beginning of the list
    store.printList(); // Print the list
    store.addTo_kth(7, 3); // Add 7 at the 3rd position in the list
    store.printList(); // Print the list
    store.del_kth(2); // Delete the node at the 2nd position in the list
    store.printList(); // Print the list
}