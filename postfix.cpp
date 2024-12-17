#include <iostream>
#include <stack>
#include <cctype>
#include <cstdlib>  // For atoi()

using namespace std;

// Function to evaluate the postfix expression
int evaluatePostfix(const string& expression) {
    stack<int> s;  // Stack to hold the operands

    for (char ch : expression) {
        if (isdigit(ch)) {
            // If the character is a digit, push it onto the stack
            s.push(ch - '0');  // Convert char to integer
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // If the character is an operator, pop two operands
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();

            // Perform the operation and push the result back onto the stack
            switch (ch) {
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
            }
        }
    }

    // The final result will be at the top of the stack
    return s.top();
}

int main() {
    string postfix;

    cout << "Enter a postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "The result of the postfix expression is: " << result << endl;

    return 0;
}
