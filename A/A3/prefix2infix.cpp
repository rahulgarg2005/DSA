#include <iostream>
using namespace std ;

class Node{
public:
    string data ;
    Node* next ;
    Node(string data) : data(data) , next(nullptr) {}
};
class Stack{
public:
    Stack() : head(nullptr) {}
    Node* head ;
    bool isEmpty(){
        return head == nullptr ;
    }

    void push(string data){
        Node* newNode = new Node(data) ;
        if(isEmpty()) {
            head = newNode ;
            return ;
        }
        newNode -> next = head ;
        head = newNode ;
    }

    string pop() {
        if(isEmpty()) return "Empty" ;
        string top = head -> data ;
        head = head -> next ;
        return top ;
    }
};

string postfixToInfix(string input){
    Stack* stack = new Stack();
    for(char ch : input){
        if(isalnum(ch)) stack -> push(string(1, ch)) ;
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
            string operand2 = stack -> pop() ;
            string operand1 = stack -> pop() ;

            string infix = "(" + operand1 + ch + operand2 + ")";
            stack -> push(infix) ;
        }
    }
    return stack -> pop() ; 
}

int main () { 
    string input = "ABD/-CD+/" ;
    string infix = postfixToInfix(input) ;
    cout << infix << endl ;
}