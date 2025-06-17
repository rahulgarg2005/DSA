#include <iostream>
using namespace std ;

class byArray{
public:
    class Queue{
    public:
        int* array ;
        int size ;
        int rear  ;

        Queue(int n){
            size = n ;
            array = new int[size] ;
            rear = -1 ;
        }

        bool isEmpty(){
            return rear == -1 ;
        }

        void add(int val){
            if(rear == size - 1){
                cout << "Queue Full" << endl ;
                return ;
            }
            rear++ ;
            array[rear] = val ;
        }

        int remove(){
            if(isEmpty()) return -1 ;
            int headVal = array[0] ;
            int i = 0 ;
            int* newArr = new int[rear] ;
            for(int j = 1 ; j < size -1 ; j++){
                newArr[i] = array[j] ;
                i++ ;
            }
            array = newArr ;
            rear-- ;
            return headVal ;
        }

        int peek(){
            if(isEmpty()) return -1 ;
            return array[0] ;
        }
    };
}; 

int main() {
    byArray::Queue q(5);
    q.add(1);
    q.add(2);
    q.add(3);

    cout << "Peek: " << q.peek() << endl; // Should print 1

    cout << "Remove: " << q.remove() << endl; // Should print 1
    cout << "Peek: " << q.peek() << endl; // Should print 2

    q.add(4);
    q.add(5);
    q.add(6); // Should print "Queue Full"

    cout << "Peek: " << q.peek() << endl; // Should print 2

    cout << "Remove: " << q.remove() << endl; // Should print 2
    cout << "Remove: " << q.remove() << endl; // Should print 3
    cout << "Remove: " << q.remove() << endl; // Should print 4
    cout << "Remove: " << q.remove() << endl; // Should print 5
    cout << "Remove: " << q.remove() << endl; // Should print "Queue Empty" and return -1

    return 0;
}