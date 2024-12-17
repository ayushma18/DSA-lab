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

void deleteFromHead(node *&head)
{
    if (head)
    {
        node *temp = head;
        cout << "Deleted " << temp->data << " from Head!\n";
        head = head->next;
        if (head)
            head->prev = NULL;
        delete temp;
    }
    else
        cout << "List is Empty!\n";
}

void deleteFromTail(node *&head)
{
    if (!head)
    {
        cout << "List is Empty!\n";
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    cout << "Deleted " << temp->data << " from Tail!\n";

    if (temp->prev)
        temp->prev->next = NULL;
    else
        head = NULL; // List becomes empty

    delete temp;
}

void deleteAfter(node *&head, int val)
{
    node *temp = head;
    while (temp && temp->data != val)
    {
        temp = temp->next;
    }

    if (!temp)
    {
        cout << "Node not Found!\n";
        return;
    }

    if (temp->next)
    {
        node *toDelete = temp->next;
        cout << "Deleted " << toDelete->data << " after " << temp->data << "!\n";

        temp->next = toDelete->next;
        if (toDelete->next)
            toDelete->next->prev = temp;

        delete toDelete;
    }
    else
    {
        cout << "No Element after " << temp->data << "!\n";
    }
}

void deleteBefore(node *&head, int val)
{
    node *temp = head;
    while (temp && temp->data != val)
    {
        temp = temp->next;
    }

    if (!temp)
    {
        cout << "Node not Found!\n";
        return;
    }

    if (temp->prev)
    {
        node *toDelete = temp->prev;
        cout << "Deleted " << toDelete->data << " before " << temp->data << "!\n";

        temp->prev = toDelete->prev;
        if (toDelete->prev)
            toDelete->prev->next = temp;
        else
            head = temp; // Update head if the first node was deleted

        delete toDelete;
    }
    else
    {
        cout << "No Element Before " << temp->data << "!\n";
    }
}

void displayLinkedList(node *head)
{
    if (!head)
    {
        cout << "List is Empty!\n";
        return;
    }

    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayMenu()
{
    cout << "5. DELETE NODE FROM BEGINNING OF THE LIST\n"
         << "6. DELETE NODE FROM END OF THE LIST\n"
         << "7. DELETE NODE AFTER SPECIFIC NODE\n"
         << "8. DELETE NODE BEFORE SPECIFIC NODE\n"
         << "9. DISPLAY THE LINKED LIST\n"
         << "ENTER 0 TO QUIT\n";
}

int main()
{
    node *head = NULL;
    int choice, value;

    displayMenu();

    do
    {
        cout << "Enter the operation you want to do: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 5:
            deleteFromHead(head);
            break;

        case 6:
            deleteFromTail(head);
            break;

        case 7:
            cout << "Enter the Value after which you want to delete the node: ";
            cin >> value;
            deleteAfter(head, value);
            break;

        case 8:
            cout << "Enter the Value before which you want to delete the node: ";
            cin >> value;
            deleteBefore(head, value);
            break;

        case 9:
            displayLinkedList(head);
            break;

        case 0:
            cout << "Thanks For Using Linked List Implementation!\n";
            break;

        default:
            cout << "Enter Valid Choice!\n";
            break;
        }
    } while (choice != 0);

    return 0;
}  