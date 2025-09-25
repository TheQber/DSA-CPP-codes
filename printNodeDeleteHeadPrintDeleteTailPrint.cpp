// You are using GCC
void append(Node*& head, int data) {
   //Type your code here
   Node* newNode = new Node(data);
   if (!head) {
       newNode->next = nullptr;
       newNode->prev = nullptr;
       head = newNode;
       return;
   }
   Node* temp = head;
   while (temp->next) {
       temp = temp->next;
   }
   newNode->next = nullptr;
   newNode->prev = temp;
   temp->next = newNode;
}

void deleteFront(Node*& head) {
   //Type your code here
   Node* temp = head->next;
   delete head;
   temp->prev = nullptr;
   head = temp;
   cout<<"First node deleted."<<endl;
}

void deleteEnd(Node*& head) {
    //Type your code here
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    Node* temp2 = temp->prev;
    delete temp;
    temp2->next = nullptr;
   cout<<"Last node deleted."<<endl;
}
void printList(Node* head) {
   //Type your code here
   Node* temp = head;
   while (temp) {
       cout<<temp->data<<" ";
       temp = temp->next;
   }
   cout<<endl;
}

void freeList(Node*& head) {
   //Type your code here
   Node* temp = head;
   while (temp->next) {
       temp = temp->next;
       delete temp->prev;
   }
}