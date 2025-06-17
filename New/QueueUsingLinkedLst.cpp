#include <iostream>
using namespace std ;

class usingLinkedList{
public:
    class Node{
    public:
        int val ;
        Node* next ;
        Node(int data) : val(data) , next(nullptr) {}
    };

    class Queue{
    public:
        Node* head = nullptr ;
        Node* tail = nullptr ;

        bool isEmpty(){
            return head == nullptr && tail == nullptr ;
        }

        void addToQueue(int val){
            Node* newNode = new Node(val) ;
            if(isEmpty()) {
                tail = head = newNode ; 
                return ;
            }
            tail -> next = newNode ;
            tail = newNode ;
        }

        int remove(){
            if(isEmpty()) return -1 ;
            int value = head -> val ;
            head = head -> next ;
            if(head == nullptr) tail = nullptr ;
            return value ;
        }

        int peek(){
            if(isEmpty()) return -1 ;
            return head -> val ;
        }
    };
};

int main(){
    usingLinkedList::Queue q ;
    q.addToQueue(1) ;
    q.addToQueue(2) ;
    q.addToQueue(3) ;
    cout << q.peek() << endl ;
}