/*
 * Student Database with Hashing (ID-Name Mapping)
 * 
 * This program implements a student database using hash table with linear probing
 * for collision resolution. It stores student ID-name pairs and provides efficient
 * lookup by student ID. The implementation uses modulo hashing and handles collisions
 * through linear probing. Input consists of number of students, followed by ID-name
 * pairs, and finally a search ID. Output displays the student name corresponding
 * to the search ID or indicates if the student is not found.
 */

//header
#include <iostream>
#include <cstring>

#define HASH_SIZE 1000

using namespace std;

struct Student {
    int id;
    char name[50];
};

Student studentDB[HASH_SIZE];

//middle code
void initDB() {
    for (int i = 0; i < HASH_SIZE; i++) {
        studentDB[i].id = -1; // mark all as empty
        strcpy(studentDB[i].name, "");
    }
}

void insertStudent(int id, const char *name) {
    int index = id % HASH_SIZE;
    int startIndex = index;

    // Linear probing in case of collision
    while (studentDB[index].id != -1 && studentDB[index].id != id) {
        index = (index + 1) % HASH_SIZE;
        if (index == startIndex) return; // full table (won’t happen here)
    }

    studentDB[index].id = id;
    strcpy(studentDB[index].name, name);
}

const char *searchStudent(int id) {
    int index = id % HASH_SIZE;
    int startIndex = index;

    while (studentDB[index].id != -1) {
        if (studentDB[index].id == id)
            return studentDB[index].name;

        index = (index + 1) % HASH_SIZE;
        if (index == startIndex)
            break; // looped back to start
    }

    return "Student not found";
}


//footer
int main() {
    initDB();

    int numStudents;
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        int id;
        char name[50];

        cin >> id;
        cin >> name;

        insertStudent(id, name);
    }

    int searchId;
    cin >> searchId;

    const char *studentName = searchStudent(searchId);
    cout << "Student name: " << studentName << endl;

    return 0;
}
