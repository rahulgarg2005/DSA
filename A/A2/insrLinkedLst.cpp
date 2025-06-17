#include <iostream>
#include <vector>
using namespace std ;

class Ques{
public:
    Ques() : head(nullptr) {}  
    struct Node{
        int val;
        Node* next,*prev;
        Node(int val): val(val) , next(nullptr) , prev(nullptr){} 
    };

    Node* head ;
    int size = 0 ;
    
    void addToLast(int val) {
        Node* newNode = new Node(val) ;
        if(head == nullptr){
            head = newNode ;
            size++ ;
            return;
        }
        Node* lastNode = head ;
        while(lastNode -> next != nullptr) lastNode = lastNode -> next ;
        lastNode -> next = newNode ;
        newNode -> prev = lastNode ;
        size++ ;
    }

    void addAtFirst(int val) {
        Node* newNode = new Node(val) ;
        if(head == nullptr){
            head = newNode ;
            size++ ;
            return ;
        }
        newNode -> next = head ; 
        head -> prev = newNode ;
        head = newNode ;
        size++ ;
    }

    void swapNodes(int k){
        if(k >= size - 1) {
            cout << "Wrong k" << endl ;
            return ;
        }
        
        Node* current = head ;
        for(int i = 0 ; i < k ; i++) current = current -> next ;

        Node* first = current ;
        Node* second = current -> next ;

        if(second == nullptr) return ;
        first -> next = second -> next ;
        if(second -> next != nullptr) second -> next -> prev = first ;

        second -> prev = first -> prev ;
        if(first -> prev != nullptr) first -> prev -> next = second ;
        else head = second ;
        second -> next = first ;
        first -> prev = second ;
    }

    void insertionSort() {
        if (head == nullptr || head->next == nullptr) return;
    
        Ques sortedList;
    
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = current->prev = nullptr; // Detach current node
    
            if (sortedList.head == nullptr || sortedList.head->val >= current->val) {
                // Insert at first position
                sortedList.addAtFirst(current->val);
            } else {
                // Find the correct position and insert
                Node* temp = sortedList.head;
                while (temp->next != nullptr && temp->next->val < current->val) {
                    temp = temp->next;
                }
                Node* newNode = new Node(current->val);
                newNode->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
    
            current = nextNode;
        }
    
        // Replace the original list with the sorted list
        head = sortedList.head;
    }
    
    void printList(){
        Node* curr = head ;
        while(curr != nullptr){
            cout << curr -> val << " <-> " ;
            curr = curr -> next ; 
        }
        cout << "NULL" << endl ;
    }
};

int main(){
    Ques list;
    list.addToLast(10);
    list.addToLast(2);
    list.addToLast(11);
    list.addToLast(14);
    list.addToLast(55);
    list.addToLast(6);
    list.addToLast(1);

    list.printList();

    list.insertionSort();

    list.printList();
} 