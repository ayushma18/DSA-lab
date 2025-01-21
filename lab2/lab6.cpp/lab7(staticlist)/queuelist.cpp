#include <iostream>

using namespace std;

const int MAX_SIZE = 100; 

struct Node {
    int data;
};

class Queue {
private:
    Node list[MAX_SIZE];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        list[rear].data = data;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int data = list[front].data;

        if (front == rear) {
            front = rear = -1; 
        } else {
            front++;
        }

        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << list[i].data << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    myQueue.display();

    cout << "Dequeued element: " << myQueue.dequeue() << endl; // Output: Dequeued element: 10

    myQueue.display(); 

    return 0;
}