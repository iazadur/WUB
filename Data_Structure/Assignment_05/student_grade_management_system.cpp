#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int grade;
};

void selectionSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].grade > arr[maxIndex].grade) {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    Student students[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name and grade of student " << i + 1 << ": ";
        cin >> students[i].name >> students[i].grade;
    }

    selectionSort(students, n);

    cout << "\nStudents sorted by grade (Descending Order):\n";
    for (int i = 0; i < n; i++) {
        cout << students[i].name << " - " << students[i].grade << endl;
    }

    return 0;
}
