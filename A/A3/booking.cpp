#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size, maxSize;
    int* queue;

public:
    CircularQueue(int maxSize) : maxSize(maxSize), front(-1), rear(-1), size(0) {
        queue = new int[maxSize]; 
    }
    
    bool isFull() const {
        return size == maxSize;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void enqueue(int ID) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1) front = 0; 
        rear = (rear + 1) % maxSize; 
        queue[rear] = ID;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1; // Indicate failure
        }
        int ID = queue[front];
        front = (front + 1) % maxSize; // Circular increment
        size--;
        return ID;
    }
};

class TicketBookingSystem {
private:
    CircularQueue queue;
    int ticketNum;

public:
    TicketBookingSystem(int queueSize) : queue(queueSize), ticketNum(1) {}

    void requestTicket(int customerID) {
        queue.enqueue(customerID);
        cout << "Ticket for " << customerID << " requested" << endl ;
    }

    void allocateTicket() {
        int customerID = queue.dequeue();
        if (customerID != -1) { // Only allocate if a valid customer ID is dequeued
            cout << "Ticket " << ticketNum << " allocated to Customer " << customerID << endl;
            ticketNum++;
        }
    }
};

int main() {
    TicketBookingSystem system(6); // Define max queue size

    system.requestTicket(101);
    system.requestTicket(102);
    system.requestTicket(103);
    system.requestTicket(104);
    system.requestTicket(105);

    system.requestTicket(106); // Should show "Queue is Full"

    // Allocate tickets
    system.allocateTicket();
    system.allocateTicket();

    // Add more customers after space is available
    system.requestTicket(106);
    system.requestTicket(107);

    // Allocate remaining tickets
    for (int i = 0; i < 5; ++i) {
        system.allocateTicket();
    }
}