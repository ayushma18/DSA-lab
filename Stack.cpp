#include <iostream>
using namespace std;

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_SIZE - 1) {
        cout << "Overflow! Stack is full. Exiting." << endl;
    } else {
        stack[++top] = item;
        cout << item << " item inserted." << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Underflow! Stack is empty. Exiting." << endl;
    } else {
        int item = stack[top--];
        cout << item << " item deleted." << endl;
    }
}

int main() {
    int choice, item;

    cout << "1. Push\n2. Pop\n";
    while (1) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> item;
                push(item);
                break;
            case 2:
                pop();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
