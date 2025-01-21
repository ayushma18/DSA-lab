#include <iostream>

using namespace std;

const int MAX_SIZE = 100; 
struct Node {
    int data;
};

class StaticList {
private:
    Node list[MAX_SIZE];
    int size;

public:
    StaticList() : size(0) {}

   
    void insertAtBeginning(int data) {
        if (size >= MAX_SIZE) {
            cout << "List is full!" << endl;
            return;
        }

        
        for (int i = size; i > 0; i--) {
            list[i] = list[i - 1];
        }

        list[0].data = data;
        size++;
    }

    void insertAtEnd(int data) {
        if (size >= MAX_SIZE) {
            cout << "List is full!" << endl;
            return;
        }

        list[size++].data = data;
    }

    void insertAfter(int data, int afterData) {
        if (size >= MAX_SIZE) {
            cout << "List is full!" << endl;
            return;
        }

        int pos = findElement(afterData);
        if (pos == -1) {
            cout << "Element not found!" << endl;
            return;
        }

        
        for (int i = size; i > pos + 1; i--) {
            list[i] = list[i - 1];
        }

        list[pos + 1].data = data;
        size++;
    }

    
    void deleteFromBeginning() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }

        
        for (int i = 0; i < size - 1; i++) {
            list[i] = list[i + 1];
        }

        size--;
    }

    void deleteFromEnd() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }

        size--;
    }

    void deleteAfter(int data) {
        int pos = findElement(data);
        if (pos == -1 || pos == size - 1) {
            cout << "Element not found or no element after it!" << endl;
            return;
        }

       
        for (int i = pos + 1; i < size - 1; i++) {
            list[i] = list[i + 1];
        }

        size--;
    }

    
    int findElement(int data) {
        for (int i = 0; i < size; i++) {
            if (list[i].data == data) {
                return i;
            }
        }
        return -1; 
    }

    
    void display() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "List: ";
        for (int i = 0; i < size; i++) {
            cout << list[i].data << " ";
        }
        cout << endl;
    }
};

int main() {
    StaticList myList;

    myList.insertAtEnd(10);
    myList.insertAtEnd(55);
    myList.insertAtEnd(23);
    myList.insertAtEnd(20);
    myList.insertAtBeginning(5);
    myList.insertAfter(15, 10);
    myList.insertAfter(4,20);

    myList.display();

    myList.deleteFromBeginning();
    myList.deleteFromEnd();
    myList.deleteAfter(23);
    myList.deleteAfter(10);


    myList.display(); 

    return 0;
}