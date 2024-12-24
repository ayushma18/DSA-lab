#include <iostream>

using namespace std;

class Stack
{
private:
    struct node
    {
        int data;
        node *next = NULL;
    };
    node *top;

public:
    Stack() : top(NULL) {}
    void push(int val)
    {
        node *n = new node{val};
        n->next = top;
        top = n;
        cout << val << " pushed to Stack!\n";
    }
    void pop()
    {
        if (top)
        {
            cout << top->data << " popped from Stack!\n";
            top = top->next;
        }
        else
        {
            cout << "Stack is Empty!\n";
        }
    }
    void display()
    {
        node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << '\t';
            temp = temp->next;
        }
        cout << endl;
    }
};


int main()
{
    system("cls");
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(12);
    s.push(43);
    s.push(32);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    return 0;
}