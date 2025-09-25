#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};
void splitList(Node *head, Node **head1_ref, Node **head2_ref) ;
void push(Node **head_ref, int data) ;
void printList(Node *head); 
// You are using GCC
void splitList(Node *head, Node **head1_ref, Node **head2_ref) { 
   //Type your code here     
   int count = 0;
   Node* temp = head;
   while (temp) {
       count++;
       temp = temp->next;
   }
   int lengthOf1;
   //int lengthof2;
   if (count%2 == 0) {
       lengthOf1 = count/2;
       //int lengthOf2 = count/2;
   }
   else {
       lengthOf1 = (count/2)+1;
       //int lengthOf2 = count/2;
   }
   Node* temp3 = head;
   int loops = 0;
   while (temp3) {
       Node* newNode = new Node();
       newNode->data = temp3->data;
       if (loops < lengthOf1) {
           if (!(*head1_ref)) {
               newNode->next = nullptr;
               *head1_ref = newNode;
           }
           else {
               Node* temp2 = *head1_ref;
               while (temp2->next) {
                   temp2 = temp2->next;
               }
               newNode->next = nullptr;
               temp2->next = newNode;
           }
       }
       else {
           if (!(*head2_ref)) {
               newNode->next = nullptr;
               *head2_ref = newNode;
           }
           else {
               Node* temp2 = *head2_ref;
               while (temp2->next) {
                   temp2 = temp2->next;
               }
               newNode->next = nullptr;
               temp2->next = newNode;
           }
       }
       loops++;
       temp3 = temp3->next;
   }
} 

void push(Node **head_ref, int data) { 
   //Type your code here     
    Node* head = *head_ref;
    Node* newNode = new Node();
    newNode->data = data;
    if (!head) {
        newNode->next = nullptr;
        head = newNode;
        *head_ref = head;
        return;
    }
    newNode->next = head;
    head = newNode;
    //cout<<"added value "<<newNode->data<<endl;
    *head_ref = head;
    //printList(*head_ref);
}  
  
void printList(Node *head) { 
  //Type your code here
  Node* temp = head;
  while (temp) {
      cout<<temp->data<<" ";
      temp = temp->next;
  }
}

int main() { 
    int list_size, i;  
    cin >> list_size;
    int arr[list_size];
    Node *head = nullptr; 
    Node *head1 = nullptr; 
    Node *head2 = nullptr;   

    for(i=0;i<list_size;i++)     {
        cin >> arr[i];
        push(&head, arr[i]);
    }

    splitList(head, &head1, &head2); 
    printList(head1); 
    cout << endl;
    printList(head2);   
    return 0; 
}