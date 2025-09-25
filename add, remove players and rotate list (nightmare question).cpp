#include <iostream>
#include <string>
using namespace std;

struct PlayerNode {
    string playerName;
    PlayerNode* next;

    PlayerNode(string name) : playerName(name), next(nullptr) {}
};

PlayerNode* head = nullptr;
// You are using GCC
int length = 0;

void addPlayer(string playerName) {
    PlayerNode* newNode = new PlayerNode(playerName);

    if (!head) {
        head = newNode;
        head->next = head;        // circular
        length = 1;
        cout << "Player " << playerName << " added to the lobby." << endl;
        return;
    }

    // insert at end (maintain insertion order)
    PlayerNode* tail = head;
    while (tail->next != head) tail = tail->next;
    tail->next = newNode;
    newNode->next = head;
    length++;
    cout << "Player " << playerName << " added to the lobby." << endl;
}

void removePlayer(string playerName) {
    if (!head) {
        cout << "The lobby is empty." << endl;
        return;
    }

    PlayerNode* curr = head;
    PlayerNode* prev = nullptr;

    // Search through circular list using do-while
    bool found = false;
    do {
        if (curr->playerName == playerName) {
            found = true;
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    if (!found) {
        // Problem statement doesn't require a "not found" message;
        // just do nothing (or uncomment a message if you need it)
        return;
    }

    // If only one node and it's being removed
    if (curr == head && curr->next == head) {
        delete curr;
        head = nullptr;
        length = 0;
        cout << "Player " << playerName << " removed from the lobby." << endl;
        return;
    }

    // Removing head (but more than 1 node)
    if (curr == head) {
        // find last node to fix circular link
        PlayerNode* last = head;
        while (last->next != head) last = last->next;
        head = head->next;
        last->next = head;
        delete curr;
        length--;
        cout << "Player " << playerName << " removed from the lobby." << endl;
        return;
    }

    // Removing non-head node (prev must be valid)
    prev->next = curr->next;
    delete curr;
    length--;
    cout << "Player " << playerName << " removed from the lobby." << endl;
}

void rotateList() {
    if (!head) {
        cout << "The lobby is empty." << endl;
        return;
    }
    head = head->next; // next player's turn
    cout << "Next player's turn: " << head->playerName << endl;
}

void displayPlayers() {
    if (!head) {
        cout << "The lobby is empty." << endl;
        return;
    }
    cout << "Players in the lobby: ";
    PlayerNode* temp = head;
    do {
        cout << temp->playerName << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void clearLobby() {
    if (!head) {
        cout << "The lobby is empty." << endl;
        return;
    }
    // delete all nodes
    PlayerNode* curr = head->next;
    while (curr != head) {
        PlayerNode* nxt = curr->next;
        delete curr;
        curr = nxt;
    }
    delete head;
    head = nullptr;
    length = 0;
    cout << "Lobby cleared." << endl;
}
int main() {
    int choice;
    string playerName;

    while (true) {
        cin >> choice;
        cin.ignore(); // Consume the newline character

        switch (choice) {
            case 1:
                getline(cin, playerName);
                addPlayer(playerName);
                break;
            case 2:
                getline(cin, playerName);
                removePlayer(playerName);
                break;
            case 3:
                rotateList();
                break;
            case 4:
                displayPlayers();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}