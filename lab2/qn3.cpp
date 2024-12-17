#include <iostream>
#define SIZE 5
using namespace std;

class Deque {
private:
    int arr[SIZE];
    int front;
    int rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

   
    void addAtBeginning(int value) {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
            cout << "Deque Overflow! Cannot insert " << value << " at the beginning." << endl;
        } else {
            if (front == -1) { 
                front = rear = 0;
            } else if (front == 0) {
                front = SIZE - 1; 
            } else {
                front--;
            }
            arr[front] = value;
            cout << value << " added at the beginning successfully!" << endl;
        }
    }

   
    void addAtEnd(int value) {
        if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
            cout << "Deque Overflow! Cannot insert " << value << " at the end." << endl;
        } else {
            if (rear == -1) { 
                front = rear = 0;
            } else if (rear == SIZE - 1) {
                rear = 0; 
            } else {
                rear++;
            }
            arr[rear] = value;
            cout << value << " added at the end successfully!" << endl;
        }
    }

   
    void deleteFromBeginning() {
        if (front == -1) { 
            cout << "Deque Underflow! Cannot delete from the beginning." << endl;
        } else {
            cout << arr[front] << " deleted from the beginning successfully!" << endl;
            if (front == rear) { 
                front = rear = -1;
            } else if (front == SIZE - 1) {
                front = 0; 
            } else {
                front++;
            }
        }
    }

    
    void deleteFromEnd() {
        if (rear == -1) {
            cout << "Deque Underflow! Cannot delete from the end." << endl;
        } else {
            cout << arr[rear] << " deleted from the end successfully!" << endl;
            if (front == rear) { 
                front = rear = -1;
            } else if (rear == 0) {
                rear = SIZE - 1; 
            } else {
                rear--;
            }
        }
    }

    
    void display() {
        if (front == -1) {
            cout << "Deque is empty!" << endl;
        } else {
            cout << "Deque elements: ";
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
    Deque dq;

    dq.addAtBeginning(10);
    dq.addAtEnd(20);
    dq.addAtBeginning(5);
    dq.addAtEnd(30);

    cout << "\nDeque after additions:" << endl;
    dq.display();

    dq.deleteFromBeginning();
    dq.deleteFromEnd();

    cout << "\nDeque after deletions:" << endl;
    dq.display();

    dq.addAtBeginning(40);
    dq.addAtEnd(50);

    cout << "\nDeque after more additions:" << endl;
    dq.display();

    return 0;
}
