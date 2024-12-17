#include <iostream>
#define SIZE 5 
using namespace std;

class LinearQueue {
private:
    int arr[SIZE]; 
    int front;     
    int rear;      
public:
    LinearQueue() {
        front = -1; 
        rear = -1;  
    }

    
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
        } else {
            if (front == -1) 
                front = 0;
            rear++;
            arr[rear] = value;
            cout << value << " enqueued successfully!" << endl;
        }
    }

   
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
        } else {
            cout << arr[front] << " dequeued successfully!" << endl;
            front++;
        }
    }

    
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    LinearQueue q;

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

    return 0;
}
