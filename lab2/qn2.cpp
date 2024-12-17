#include <iostream>
#define SIZE 5
using namespace std;

class CircularQueue {
private:
    int arr[SIZE]; 
    int front;     
    int rear;      

public:
    CircularQueue() {
        front = -1; 
        rear = -1;  
    }

    
    void enqueue(int value) {
        if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
        } else {
            if (front == -1) // Queue is initially empty
                front = 0;

            rear = (rear + 1) % SIZE; // Circular increment
            arr[rear] = value;
            cout << value << " enqueued successfully!" << endl;
        }
    }

    
    void dequeue() {
        if (front == -1) { 
            cout << "Queue Underflow! Cannot dequeue." << endl;
        } else {
            cout << arr[front] << " dequeued successfully!" << endl;

            if (front == rear) { 
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % SIZE; 
            }
        }
    }

    
    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % SIZE; 
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);
    q.display();

    return 0;
}
