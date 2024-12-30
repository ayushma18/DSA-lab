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
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
void deleteAfterNode(Node* head, int targetData) {
    Node* temp = head;
    while (temp != nullptr && temp->data != targetData) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        cout << "No node found to delete after the specified node." << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}


void deleteBeforeNode(Node*& head, int targetData) {
    if (head == nullptr || head->next == nullptr) {
        cout << "List is too short, nothing to delete." << endl;
        return;
    }
    if (head->next->data == targetData) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr && temp->next->next->data != targetData) {
        temp = temp->next;
    }
    if (temp->next->next == nullptr) {
        cout << "No node found to delete before the specified node." << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
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

    
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    displayList(head);

    
    deleteFromBeginning(head);
    displayList(head);
    deleteFromEnd(head);
    displayList(head);
    deleteAfterNode(head, 20);
    displayList(head);
    deleteBeforeNode(head, 40);
    displayList(head);

    return 0;
}
