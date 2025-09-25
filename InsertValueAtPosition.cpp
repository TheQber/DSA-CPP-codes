// You are using GCC
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(DoublyLinkedList* dList, int data) {
    Node* newNode = createNode(data);
    if (dList->head == NULL) {
        dList->head = dList->tail = newNode;
    } else {
        dList->tail->next = newNode;
        newNode->prev = dList->tail;
        dList->tail = newNode;
    }
}

void insertAtMiddle(DoublyLinkedList* dList, int data, int position) {
    // count length
    int length = 0;
    Node* temp = dList->head;
    while (temp) {
        length++;
        temp = temp->next;
    }

    // invalid position (1-based indexing)
    if (position < 1 || position > length) {
        cout << "Invalid position" << endl;
        return;
    }

    Node* newNode = createNode(data);

    // Case 1: insert at beginning
    if (position == 1) {
        newNode->next = dList->head;
        if (dList->head) dList->head->prev = newNode;
        dList->head = newNode;
        if (dList->tail == NULL) dList->tail = newNode;
        return;
    }

    // Case 2: insert at end (before tail)
    if (position == length) {
        newNode->next = dList->tail;
        newNode->prev = dList->tail->prev;
        if (dList->tail->prev) dList->tail->prev->next = newNode;
        dList->tail->prev = newNode;
        // if inserting before head when only 1 element
        if (position == 1) dList->head = newNode;
        return;
    }

    // Case 3: insert in middle
    temp = dList->head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void displayList(DoublyLinkedList* dList) {
    Node* temp = dList->head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}