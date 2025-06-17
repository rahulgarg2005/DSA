#include <iostream>
#include <string>
using namespace std ;

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
    bool isEmpty(){
        return head == nullptr ;
    }

    void push(int val){
        Node* newNode = new Node(val) ;
        if(isEmpty()){
            head = newNode ;
            return ;
        }
        newNode -> next = head ;
        head = newNode ;
    }

    int pop(){
        if(isEmpty()) return -1 ;
        int top = head -> val ;
        head = head -> next ;
        return top ;
    }    
};

bool isValid(Stack &stck , string &s){
    for(char ch : s){
        if(ch == '(' || ch == '[' || ch == '{') stck.push(ch) ;
        else{
            if(stck.isEmpty()) return false ;
            char top = stck.pop() ;
            if( (ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[') ){
                return false ;
            }
        }
    }
    return stck.isEmpty() ;
}

int main(){
    string s = "({[]})" ;
    Stack stck ;
    // createStack(stck , s) ;
    isValid(stck , s) ? (cout << "True" << endl) : (cout << "False" << endl) ; ;
}