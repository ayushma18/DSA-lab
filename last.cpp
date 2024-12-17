#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if the parentheses are balanced
bool checkParentheses(const string& expression) {
    stack<char> s;  // Stack to store opening parentheses

    for (char ch : expression) {
        // If we encounter an opening parenthesis, push it to the stack
        if (ch == '(') {
            s.push(ch);
        }
        // If we encounter a closing parenthesis
        else if (ch == ')') {
            // Check if the stack is empty (no opening parenthesis to match)
            if (s.empty()) {
                return false;  // Unmatched closing parenthesis
            }
            // Pop the opening parenthesis from the stack
            s.pop();
        }
    }

    // If the stack is empty, parentheses are balanced, otherwise they are not
    return s.empty();
}

int main() {
    string expression;

    cout << "Enter a mathematical expression: ";
    cin >> expression;

    // Check if the parentheses are balanced
    if (checkParentheses(expression)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are NOT balanced." << endl;
    }

    return 0;
}
