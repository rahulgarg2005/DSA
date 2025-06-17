#include <iostream>
#include <algorithm>
using namespace std;

class Node{
public:
    char data ;
    Node* next ;
    Node(char data) : data(data) , next(nullptr) {}
};

class Stack{
public:
    Stack() : head(nullptr) {}
    Node* head ;

    bool isEmpty(){
        return head == nullptr ;
    } 
    void push(char val){
        Node* newNode = new Node(val) ;
        if(isEmpty()) {
            head = newNode ; 
            return ;
        }
        newNode -> next = head ;
        head = newNode ;
    }
    char pop(){
        if(isEmpty()) return 'E' ;
        char top = head -> data ;
        head = head -> next ;
        return top ;
    }    
    char peek(){
        if(isEmpty()) return -1 ;
        return head -> data ;
    }
};

int precedence(char op){
    if(op == '^') return 3 ;
    if(op == '*' || op == '/') return 2 ; 
    if(op == '+' || op == '-') return 1 ; 
    else return 0;
}

string infixToPostfix(string input){
    Stack* stack = new Stack() ;
    string output = "" ;
    for(char ch : input){
        if(isalnum(ch)) output += ch ;
        else if (ch == '(') stack -> push(ch) ;
        else if (ch == ')') {
            while(!stack -> isEmpty() && stack -> peek() != '(') output += stack -> pop() ;
            stack -> pop() ;
        }
        else{
            while(!stack -> isEmpty() && precedence(ch) < precedence(stack -> peek())) output += stack -> pop() ;
            stack -> push(ch) ;
        }
    }
    while(!stack -> isEmpty()) output += stack -> pop() ;
    return output;
    delete stack ; 
}
string infixToPrefix(string infix) {
    // 1. Reverse the infix string
    reverse(infix.begin(), infix.end());

    // 2. Swap parentheses
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // 3. Convert to postfix
    string postfix = infixToPostfix(infix);

    // 4. Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}


int main() { 
    string input = "(A-(B/D))/(C+D)" ;
    infixToPostfix(input) ;
}