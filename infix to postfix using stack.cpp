/*
 * Infix to Postfix Conversion Using Stack
 * 
 * This program converts mathematical expressions from infix notation to postfix notation
 * using a stack-based algorithm. It handles operator precedence (^, *, /, +, -) and parentheses
 * to ensure correct conversion. The algorithm processes each character, pushing operators
 * onto the stack based on precedence rules and popping when appropriate. Input consists of
 * an infix expression string. Output displays the equivalent postfix expression.
 */

// You are using GCC
#include <iostream>
using namespace std;
class Stack {
    public:
    char data[100];
    int top = -1;
    Stack() {
        top = -1;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == 99;
    }
    char push(char val) {
        data[++top] = val;
        return val;
    }
    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        return data[top--]; 
    }
    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return data[top];
    }
};
#include <cctype>
class InfixToPostfix {
    public:
    string output = "";
    Stack s;
    int checkPrecedence(char c) {
        if (c == '^') {
            return 3;
        }
        else if (c == '*' || c == '/') {
            return 2;
        }
        else if (c == '+' || c == '-') {
            return 1;
        }
        else {
            return -1;
        }
    }
    string convert(string input) {
        for (char c: input) {
            if (isalnum(c)) {
                output += c;
            }
            else if (c == '^' || c == '/' || c == '*' || c == '+' || c == '-') {
                while (!s.isEmpty() && (checkPrecedence(s.peek()) >= checkPrecedence(c))) {
                    output += s.pop();
                }
                s.push(c);
            }
            else if (c == '(') {
                s.push(c);
            }
            else if (c == ')') {
                while (!s.isEmpty() && s.peek() != '(') {
                    output+= s.pop();
                }
                s.pop();
            }
        }
        while (!s.isEmpty()) {
            output+=s.pop();
        }
        return output;
    }
};
int main() {
    string input;
    cin>>input;
    InfixToPostfix i;
    cout<<i.convert(input);
}