#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

char stack[20];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return -1;
}

int main() {
    char exp[20];
    char *e, x;

    cout << "Enter the expression: ";
    cin >> exp;
    e = exp;

    while (*e != '\0') {
        if (isalnum(*e)) {
            // Print operands directly
            cout << *e;
        } else if (*e == '(') {
            // Push '(' onto the stack
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(') {
                cout << x;
            }
        } else {
            // Handle operators
            while (priority(stack[top]) >= priority(*e)) {
                cout << pop();
            }
            push(*e);
        }
        e++;
    }

    // Pop and print remaining operators
    while (top != -1) {
        cout << pop();
    }

    return 0;
}
