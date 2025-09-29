#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Student {
    string name;
    float gpa;
    int age;
    string major;
};

// Comparison function depending on criterion
bool compare(const Student &a, const Student &b, const string &criterion) {
    if (criterion == "gpa") return a.gpa < b.gpa;
    if (criterion == "age") return a.age < b.age;
    if (criterion == "major") return a.major < b.major;
    return false;
}

// Partition function for quicksort
int partition(vector<Student> &arr, int low, int high, const string &criterion) {
    Student pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot, criterion)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort implementation
void quickSort(vector<Student> &arr, int low, int high, const string &criterion) {
    if (low < high) {
        int pi = partition(arr, low, high, criterion);
        quickSort(arr, low, pi - 1, criterion);
        quickSort(arr, pi + 1, high, criterion);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        cin >> students[i].name;
        cin >> students[i].gpa;
        cin >> students[i].age;
        cin >> students[i].major;
    }

    string criterion;
    cin >> criterion;

    quickSort(students, 0, n - 1, criterion);

    cout << "Sorted Student Records:\n";
    cout << "Name\t\tGPA\t\tAge\t\tMajor\n";

    for (auto &s : students) {
        cout << left << setw(10) << s.name << "\t"
             << fixed << setprecision(2) << s.gpa << "\t"
             << s.age << "\t\t"
             << s.major << "\n";
    }

    return 0;
}
