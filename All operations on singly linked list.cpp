// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};
Node* start = nullptr;
// You are using GCC
Node* ending = nullptr;
Node* head = start;
Node* tail = ending;
int length = 0;
void traverse() {
   //Type your code here
   Node* temp = head;
   while (temp) {
       if (length == 0) {
           cout<<"List is empty"<<endl;
           return;
       }
       cout<<temp->data<<" ";
       temp = temp->next;
   }
 
   cout<<endl;
   
}

void insertAtFront() {
   //Type your code here
   int val;
   cin>>val;
   Node* newNode = new Node(val);
   if (!head) {
       tail = head = newNode;
       length++;
       return;
   }
   newNode->next = head;
   head->prev = newNode;
   head = newNode;
   length++;
   
}

void insertAtEnd() {
   //Type your code here
   int val;
   cin>>val;
   Node* newNode = new Node(val);
   if (!tail) {
       tail = head = newNode;
       length++;
       return;
   }
   newNode->prev = tail;
   tail->next = newNode;
   tail = newNode;
   length++;
}

void insertAtPosition() {
    //Type your code here
    int pos, value;
    cin>>pos>>value;
    if (pos > length+1) {
        cout<<"Position out of range"<<endl;
    }
    int count = 1;
    Node* temp = head;
    while (temp->next) {
        if (pos == 1) {
           Node* newNode = new Node(value);
           if (!head) {
               tail = head = newNode;
               length++;
               cout<<"Node Inserted"<<endl;
               return;
           }
           newNode->next = head;
           head = newNode;
           length++;
           cout<<"Node Inserted"<<endl;
           return;
        }
        if (pos == length) {
           Node* newNode = new Node(value);
           
           Node* temp2 = tail->prev;
           
           newNode->next = tail;
           temp2->next = newNode;
           newNode->prev = temp2;
           tail->prev = newNode;
            length++;
            cout<<"Node Inserted"<<endl;
            return;
        }
        if (pos == length+1) {
           Node* newNode = new Node(value);
           
           Node* temp2 = tail;
           
           newNode->next = nullptr;
           temp2->next = newNode;
           newNode->prev = temp2;
           tail = newNode;
            length++;
            cout<<"Node Inserted"<<endl;
            return;
        }
        if (count == pos) {
            Node* newNode = new Node(value); 
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            cout<<"Node Inserted"<<endl;
            return;
        }
        count++;
        temp = temp->next;
    }
}

void deleteFirst() {
    //Type your code here
    if (length == 0) {
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head->next;
    delete head;
    head = temp;
    length--;
}

void deleteEnd() {
   //Type your code here
    if (length == 0) {
        cout<<"List is empty"<<endl;
        return;
    }
   Node* temp = tail->prev;
   delete tail;
   temp->next = nullptr;
   tail = temp;
   length--;
}

void deletePosition() {
   //Type your code here
    if (length == 0) {
        cout<<"List is empty"<<endl;
        return;
    }
   int pos;
   cin>>pos;
   int count = 1;
   Node* temp = head;
   while (temp) {
       if (pos == 1) {
           head = head->next;
           head->prev = nullptr;
           length--;
           return;
       }
       if (pos == length) {
           tail = tail->prev;
           tail->next = nullptr;
           
           length--;
           return;
       }
       if (count == pos) {
           temp->prev->next = temp->next;
           temp->next->prev = temp->prev;
           length--;
           delete temp;
           return;
       }
       count++;
       temp = temp->next;
   }
   cout<<"Position out of range"<<endl;
}

void search() {
   //Type your code here
   int val;
   cin>>val;
   Node* temp = head;
   int count = 1;
   while (temp) {
       if (temp->data == val) {
           cout<<"The element "<<val<<" is at index "<<count<<" in the list"<<endl;
           return;
       }
       temp = temp->next;
       count++;
   }
   cout<<"the element "<<val<<" is not found in the list"<<endl;
}

int main() {
    int choice;
    while (true) {
        cin >> choice;
        switch (choice) {
            case 1: insertAtFront(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteFirst(); break;
            case 5: deleteEnd(); break;
            case 6: deletePosition(); break;
            case 7: search(); break;
            case 8: traverse(); break;
            case 9: return 0;
            default: cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}
