#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAfterNode(Node* head, int targetData, int data) {
    Node* temp = head;
    while (temp != nullptr && temp->data != targetData) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Target node not found." << endl;
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}


void insertBeforeNode(Node*& head, int targetData, int data) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == targetData) {
        insertAtBeginning(head, data);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != targetData) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Target node not found." << endl;
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}


void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    
    insertAtBeginning(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    displayList(head);

    insertAfterNode(head, 2, 50);
    displayList(head);
    insertBeforeNode(head, 2, 20);
    displayList(head);

    return 0;
}
