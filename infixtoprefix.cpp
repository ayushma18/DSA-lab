#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
#include <algorithm>  // For reverse

using namespace std;

// Function to check if the character is an operand (digit or alphabet)
bool isOperand(char ch) {
    return isdigit(ch) || isalpha(ch);  // Operand is a digit or an alphabet
}

// Function to return the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to perform infix to postfix conversion
void infixToPostfix(string& exp) {
    stack<char> s;
    string result = "";
    
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        
        if (isOperand(ch)) {
            result += ch;  // If operand, add to result
        } 
        else if (ch == '(') {
            s.push(ch);  // If '(', push to stack
        } 
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();  // Pop operators from stack until '('
                s.pop();
            }
            s.pop();  // Remove '('
        } 
        else {  // Operator
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                result += s.top();  // Pop operators with higher or equal precedence
                s.pop();
            }
            s.push(ch);  // Push current operator to stack
        }
    }
    
    // Pop remaining operators in stack
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    exp = result;  // Store result in exp
}

// Function to convert infix to prefix
void infixToPrefix(string exp) {
    // Step 1: Reverse the expression
    reverse(exp.begin(), exp.end());
    
    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
    
    // Step 3: Convert the reversed expression to postfix
    infixToPostfix(exp);

    // Step 4: Reverse the postfix expression to get the prefix expression
    reverse(exp.begin(), exp.end());

    cout << "Prefix Expression: " << exp << endl;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    // Convert the infix expression to prefix
    infixToPrefix(infix);

    return 0;
}
 