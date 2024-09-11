#include <iostream>
#include <stack>
#include <string>
#include <cctype> // for isalpha()

using namespace std;

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return -1;
    }
}

void infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;
    
    for (char c : infix) {
        if (isalpha(c)) {
            // If the character is an operand, add it to the postfix string
            postfix += c;
        } else if (c == '(') {
            // If the character is '(', push it to the stack
            s.push(c);
        } else if (c == ')') {
            // If the character is ')', pop from the stack until '(' is encountered
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop(); // pop '('
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            // If the character is an operator
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        } else {
            // Handle invalid characters
            cerr << "Invalid character '" << c << "' in the expression.\n";
            return;
        }
    }
    
    // Pop all remaining operators in the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    cout << "The Postfix Expression is: " << postfix << '\n';
}

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    infixToPostfix(infix);
    return 0;
}

