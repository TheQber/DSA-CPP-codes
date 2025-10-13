/*
 * Traffic Light Priority Queue Based on Traffic Volume
 * 
 * This program manages traffic light switching order based on traffic volume using a
 * priority queue implementation. Roads with higher traffic volume (priority) are given
 * precedence in the switching sequence. The implementation uses a linked list with
 * sorted insertion to maintain proper priority ordering. Input consists of number of
 * roads followed by road number and traffic volume for each road. Output displays
 * the traffic light switching order with volume information.
 */

//You are using GCC
// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    int priority;
    Node* next;
};
class LinkedList {
    public:
    Node* top = NULL;
    void push(int val, int p) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->priority = p;
        if (!top) {
            newNode->next = NULL;
            top = newNode;
            //printList();
            return;
        }
        Node* temp1 = top;
        Node* temp2 = temp1;
        if (temp1->priority<newNode->priority) {
            newNode->next = temp1;
            top = newNode;
            //printList();
            return;
        }
        while ((temp1->priority)>=(newNode->priority)) {
            if (temp1->next) {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            else {
                newNode->next = NULL;
                temp1->next = newNode;
                //printList();    
                return;
            }
        }
        newNode->next = temp2->next;
        temp2->next = newNode;
        //printList();    
        return;
    }
    void printList() {
        Node* temp = top;
        cout<<"Traffic Light Switching Order:"<<endl;
        while (temp) {
            cout<<"Switch traffic light to Road "<<temp->data<<" with traffic volume "<<temp->priority<<"."<<endl;
            temp = temp->next;
        }
    }
};
int main() {
    int size;
    cin>>size;
    if (size < 1) {
        cout<<"Invalid number of roads.";
        return 0;
    }
    int val,prio;
    LinkedList l;
    for (int i = 0 ; i < size ; i ++) {
        cin>>val>>prio;
        l.push(val,prio);
    }
    l.printList();
}