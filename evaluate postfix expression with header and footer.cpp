//header
#include <iostream>
#include <sstream>
#include <cctype>
#include <cmath>

#define MAX 100

using namespace std;

struct Stack {
    int top;
    double arr[MAX];

    Stack() { top = -1; }
};

bool isEmpty(Stack &stack) {
    return stack.top == -1;
}

bool isFull(Stack &stack) {
    return stack.top == MAX - 1;
}
//middle code
// You are using GCC
int push(Stack &s, int val) {
    //Type your code here
    s.arr[++s.top] = val;
    return val;
}

int pop(Stack &s) {
    //Type your code here
    if (isEmpty(s)) {
            return -1;
    }
    return s.arr[s.top--]; 
}

int peek(Stack &s) {
    //Type your code here
    if (isEmpty(s)) {
            return -1;
    }
    return s.arr[s.top];
}

bool isNumber(const char str) {
    //Type your code here
    int ar[10] = {0,1,2,3,4,5,6,7,8,9};
    for (int n: ar) {
        if (n == str-'0') {
            return true;
        }
    }
    return false;
}

double evaluatePostfixExpression(const string input) {
    Stack s;
    for (char c: input) {
        if (isNumber(c)) {
            push(s,c-'0');
        }
        else {
            if (c == '/') {
                int b = pop(s);
                int a = pop(s);
                push(s,a/b);
            }
            else if (c == '*') {
                int b = pop(s);
                int a = pop(s);
                push(s,a*b);
            }
            else if (c == '+') {
                int b = pop(s);
                int a = pop(s);
                push(s,a+b);
            }
            else if (c == '-') {
                int b = pop(s);
                int a = pop(s);
                push(s,a-b);
            }
            
        }
    }
    return pop(s);
}
//footer
int main() {
    string expression;
    getline(cin, expression);

    double result = evaluatePostfixExpression(expression);
    cout << result;

    return 0;
}