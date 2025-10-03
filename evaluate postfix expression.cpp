// You are using GCC
#include <iostream>
using namespace std;
class Stack {
    public:
    int data[100];
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
    int push(int val) {
        data[++top] = val;
        return val;
    }
    int pop() {
        if (isEmpty()) {
            return -1;
        }
        return data[top--]; 
    }
    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return data[top];
    }
};
class Evaluate {
    public:
    Stack s;
    bool isNumber(char c) {
        int arr[10] = {0,1,2,3,4,5,6,7,8,9};
        for (int d: arr) {
            if (c-'0' == d) {
                return true;
            }
        }
        return false;
    }
    int calculate(string input) {
        for (char c: input) {
            if (isNumber(c)) {
                s.push(c-'0');
            }
            else {
                if (c == '/') {
                    int b = s.pop();
                    int a = s.pop();
                    s.push(a/b);
                }
                else if (c == '*') {
                    int b = s.pop();
                    int a = s.pop();
                    s.push(a*b);
                }
                else if (c == '+') {
                    int b = s.pop();
                    int a = s.pop();
                    s.push(a+b);
                }
                else if (c == '-') {
                    int b = s.pop();
                    int a = s.pop();
                    s.push(a-b);
                }
                
            }
        }
        return s.pop();
    }
};
#include <algorithm>
int main() {
    string input;
    getline(cin,input);
    Evaluate e;
    cout<<e.calculate(input);
}