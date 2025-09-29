// You are using GCC
// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
int main() {
    int size;
    cin>>size;
    int val;
    Node* l[size];
    for (int i = 0 ; i < size ; i ++) {
        cin>>val;
        l[i] = new Node(val);
    }
    Node* head = l[0];
    int r = 0;
    Node* tail = l[size-1];
    bool used[size] = {false};
    for (int i = 0 ; i < size ; i ++ ) {
        if (l[i]->data<head->data) {
            head = l[i];
            r = i;
        }
        if (l[i]->data>tail->data) {
            tail = l[i];
        }
    }
    used[r] = true;
    Node* lastNode = head;
    bool unsorted = true;
    int t = -1;
    while (unsorted) {
        Node* minVal = tail;
        for (int i = 0 ; i < size ; i ++) {
            if ((l[i]->data)>=(lastNode->data) && (l[i]->data)<(minVal->data) && !used[i]) {
                minVal = l[i];
                t = i;
            }
        }
        lastNode->next = minVal;
        lastNode = minVal;
        used[t] = true;
        if (minVal == tail) {
            unsorted = false;
        }
    }
    Node* temp = head;
    while (temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
}
