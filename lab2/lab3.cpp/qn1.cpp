#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
        head->prev = n;
    head = n;
    cout << "Added " << val << " to the Head of Linked List!\n";
}

void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        cout << "Linked List Initialized! \n";
        insertAtHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    cout << "Added " << val << " to the Tail of Linked List!\n";
}

void displayLinkedList(node *head)
{
    node *temp = head;
    cout << "\nThe contents of the Linked List Are: \n";
    while (temp != NULL)
    {
        cout << temp->data << " <--> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAfterN(node *&head, int val, int index)
{
    int count = 0;
    node *temp = head;
    node *n = new node(val);
    while (temp->next != NULL && count != index)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL && count != index)
    {
        cout << "Index out of Bound!\n";
        delete n;
        return;
    }
    temp->next->prev = n;
    n->next = temp->next;
    temp->next = n;
    n->prev = temp;
    cout << val << " inserted after index " << index << endl;
}

void insertBeforeN(node *&head, int val, int index)
{
    int count = 0;
    node *temp = head;
    node *n = new node(val);
    while (temp != NULL && count != index)
    {
        ++count;
        temp = temp->next;
    }
    if (temp == NULL && count != index)
    {
        cout << "Index out of Bound!\n";
        delete n;
        return;
    }
    temp->prev->next = n;
    n->prev = temp->prev;
    n->next = temp;
    temp->prev = n;
    cout << val << " inserted before index " << index << endl;
}

void displayMenu()
{
    cout << "\n--- Menu ---\n";
    cout << "1. Insert at Head\n";
    cout << "2. Insert at Tail\n";
    cout << "3. Insert after a Node\n";
    cout << "4. Insert before a Node\n";
    cout << "5. Display Linked List\n";
    cout << "6. Exit\n";
}

int main()
{
    system("cls");
    node *head = NULL;
    int choice, value, index;
    do
    {
        displayMenu();
        cout << "Enter the operation you want to do: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the Value that you want to insert at the beginning: ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 2:
            cout << "Enter the Value that you want to insert at the end: ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 3:
            cout << "Enter the Value that you want to insert after the node: ";
            cin >> value;
            cout << "Enter the index after which you want to insert the value: ";
            cin >> index;
            insertAfterN(head, value, index);
            break;

        case 4:
            cout << "Enter the Value that you want to insert before the node: ";
            cin >> value;
            cout << "Enter the index before which you want to insert the value: ";
            cin >> index;
            insertBeforeN(head, value, index);
            break;

        case 5:
            displayLinkedList(head);
            break;

        case 6:
            cout << "Exiting Program.\n";
            break;

        default:
            cout << "Invalid Choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}