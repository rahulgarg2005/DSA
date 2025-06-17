#include <iostream>
using namespace std ;

class Sort{
public:
    Sort() : head(nullptr) {}
    class Node{
    public:
        int val ;
        Node* next ;
        Node* prev ;
        Node(int val) : val(val) , next(nullptr) , prev(nullptr) {}
    };
    Node* head ;
    int size = 0 ;

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

    void insertionSort(){
        if (head == nullptr || head->next == nullptr) return;

        Node* current = head ;
        Sort sortedList ;
        while(current != nullptr){
            Node* nextNode = current -> next ;
            current -> next = current -> prev = nullptr ;

            if(sortedList.head == nullptr || sortedList.head -> val >= current -> val)  sortedList.addAtFirst(current -> val) ;
            else{
                Node* temp = sortedList.head ;
                while(temp -> next != nullptr && temp -> next -> val < current -> val) temp = temp -> next ;

                Node* newNode = new Node(current -> val) ;
                newNode -> next = temp -> next ;
                if(temp -> next != nullptr) temp -> next -> prev = newNode ;
                temp -> next = newNode ;
                newNode -> prev = temp ;

            }
            current = nextNode ;
        } 
        head = sortedList.head ;
    }
    void printList(){
        if(head == nullptr) return ;
        Node* curr = head ;
        while(curr != nullptr) {
            cout << curr -> val <<" <-> " ;
            curr = curr -> next ;
        }
        cout << "NULL" << endl ;
    }

};

int main(){
    Sort list;
    list.addAtFirst(10);
    list.addAtFirst(2);
    list.addAtFirst(11);
    list.addAtFirst(14);
    list.addAtFirst(55);
    list.addAtFirst(6);
    list.addAtFirst(1);

    list.printList();

    list.insertionSort();

    list.printList();
}