#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

class LinkedList {
public:
    Node* head = nullptr; // 'head' in this scheme points to the node used as the start for printing
    int length = 0;

    // Insert the new node AFTER head, then make new node the head.
    // If list empty -> new node points to itself and becomes head.
    void pushToBeg(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = newNode;
        } else {
            // insert after head
            newNode->next = head->next;
            head->next = newNode;
            // make the newly inserted node the new head (so printing starts at this node)
            head = newNode;
        }
        length++;
    }

    // Delete first node with matching value.
    // If list empty -> print empty message per spec.
    // If value not found -> print "ID X is not present."
    // If deleting head: set head = head->next (or nullptr if single node).
    void deleteValue(int val) {
        if (!head) {
            cout << "The lobby is empty." << endl;
            return;
        }

        // Single-node case?
        if (head->next == head) {
            if (head->data == val) {
                delete head;
                head = nullptr;
                length = 0;
                cout << "Deleted process ID: " << val << endl;
            } else {
                cout << "ID " << val << " is not present." << endl;
            }
            return;
        }

        // If head itself holds the value:
        if (head->data == val) {
            // find previous (tail) to relink
            Node* prev = head;
            while (prev->next != head) prev = prev->next;
            prev->next = head->next;
            Node* del = head;
            head = head->next;          // as explained, set head to next node
            delete del;
            length--;
            cout << "Deleted process ID: " << val << endl;
            return;
        }

        // Search the rest of the list
        Node* prev = head;
        Node* curr = head->next;
        while (curr != head && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == head) {
            cout << "ID " << val << " is not present." << endl;
            return;
        }
        // unlink curr
        prev->next = curr->next;
        delete curr;
        length--;
        cout << "Deleted process ID: " << val << endl;
    }

    // Display starting from head, looping once; if empty print empty message.
    void printList() {
        if (!head) {
            cout << "The lobby is empty." << endl;
            return;
        }
        cout << "Current processes: ";
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main() {
    int command, val;
    LinkedList l;
    while (true) {
        cin >> command;
        if (command == 1) {
            cin >> val;
            l.pushToBeg(val);
        } else if (command == 2) {
            cin >> val;
            l.deleteValue(val);
        } else if (command == 3) {
            l.printList();
        } else if (command == 4) {
            return 0;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}