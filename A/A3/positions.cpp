#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void addToLast(int value) {
        if (head == nullptr) {
            head = new Node(value);
            return;
        }
        Node* current = head;
        while (current->next) current = current->next;
        current->next = new Node(value);
    }

    void findPositions(int a) {
        vector<Node*> trackers(a - 1, nullptr); // Create trackers for positions n/2, n/3, ..., n/a
        Node* current = head;
        int count = 1;

        // Initialize trackers with head at start
        for (int i = 0; i < trackers.size(); i++) {
            trackers[i] = head;
        }

        // Traverse the linked list and update trackers
        while (count <= a) {
            for (int i = 0; i < trackers.size(); i++) {
                if (count % (i + 2) == 0) { // Update trackers based on n/i positions
                    trackers[i] = trackers[i]->next;
                    // else  trackers[i] = nullptr;
                }
            }
            count++;
        }

        // Print results for each n/i position
        for (int i = 0; i < trackers.size(); i++) {
            cout << "Element at n/" << (i + 2) << ": " << (trackers[i] -> data) << endl;
        }
    }
};

int main() {
    LinkedList ll;
    int a;
    cout << "Enter the number of elements in the linked list: ";
    cin >> a;

    for (int i = 0; i < a; ++i) {
        int value;
        cin >> value;
        ll.addToLast(value);
    }

    // Find and print the elements at required positions
    ll.findPositions(a);
}