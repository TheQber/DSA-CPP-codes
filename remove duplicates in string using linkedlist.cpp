/*
 * Remove Duplicates from String Using Linked List
 * 
 * This program removes duplicate characters from a string using a linked list
 * data structure. It processes each character of the input string and only
 * adds characters that haven't been seen before. The implementation uses a
 * stack-like linked list with push, pop, and contains operations to track
 * unique characters. Input consists of a string. Output displays the string
 * with all duplicate characters removed while preserving order.
 */

//header
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* top = nullptr; 
//middle code
// You are using GCC
Node* head = nullptr;
#include <string>
int length = 0;
void push(char value) {
    //Type your code here
    Node* newNode = new Node();
    newNode->data = value;
    if (!head) {
        newNode->next = nullptr;
        head = newNode;
        length++;
        return;
    }
    newNode->next = head;
    head = newNode;
    length++;
}

char pop() {
    //Type your code here
    if (!head) {
        return '0';
    }
    Node* temp = head;
    head = head->next;
    char val = temp->data;
    delete temp;
    return val;
}

bool contains(char value) {
    //Type your code here
    if (!head) {
        return false;
    }
    Node* temp = head;
    while (temp) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

string getResult() {
    //Type your code here
    string s = "";
    Node* temp = head;
    while (temp) {
        s = temp->data + s;
        temp = temp->next;
    }
    return s;
}

string removeDuplicates(string str) {
    //Type your code here
    int length = str.length();
    for (int i = 0 ; i < length ; i ++) {
        if (!contains(str[i])) {
            push(str[i]);
        }
    }
    string s = getResult();
    return s;
}

void clearStack() {
    //Type your code here
}
//footer
int main() {
    string str;
    cin >> str;
    cout << "After removing duplicates: " << removeDuplicates(str);
    clearStack(); 
    return 0;
}