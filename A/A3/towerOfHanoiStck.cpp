#include <iostream>
#include <string>
using namespace std;


class Node{
public: 
    int val ;
    Node* next ; 
    Node(int val) : val(val) , next(nullptr) {}
};

class Stack{
public:
    Stack() : head(nullptr) {}
    Node* head ;

    bool isEmpty() {
        return head == nullptr ;
    }
                                   
    void push(int val){
        Node* newNode = new Node(val) ;
        if(isEmpty()) {
            head = newNode ; 
            return ;
        }
        newNode -> next = head ;
        head = newNode ; 
    }
           
    int pop(){
        if(isEmpty()) return -1;
        int top = head -> val ;
        head = head -> next ;
        return top ;
    }
};

void createStack(Stack &s , int nDiscs){
    for(int i = nDiscs ; i >= 1 ; i--) s.push(i) ;
}

void moveDisc(Stack &source , Stack &detination , string from , string to ){
    int disc = source.pop() ;
    detination.push(disc) ;
    cout << "Move disc " << disc << " from " << from << " to " << to << endl ;                
}

void towerOfHanoi(int nDiscs , Stack &src , Stack &help , Stack &des , string tower1 , string tower2 , string tower3){
    if(nDiscs == 1){
        moveDisc(src , des , tower1 , tower3) ;
        return ; 
    }
    towerOfHanoi(nDiscs - 1 , src , des , help , tower1 , tower3 , tower2) ;
    moveDisc(src , des , tower1 , tower3) ;
    towerOfHanoi(nDiscs - 1 , help , src , des , tower2 , tower1 , tower3) ;
}


int main(){
    Stack* src = new Stack();
    Stack* help = new Stack();
    Stack* des = new Stack();
    int nDiscs = 3;
    createStack(*src , nDiscs) ;
    towerOfHanoi(nDiscs , *src , *help , *des , "Tower1", "Tower2", "Tower3") ;
    
}