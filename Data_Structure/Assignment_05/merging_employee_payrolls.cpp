// merging_employee_payrolls

#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

void merge(Employee arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Employee L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].id <= R[j].id)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Employee arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n1, n2;
    cout << "Enter the number of employees in Department 1: ";
    cin >> n1;
    Employee dept1[n1];
    cout << "Enter ID, Name, Salary for Department 1 employees:\n";
    for (int i = 0; i < n1; i++) {
        cin >> dept1[i].id >> dept1[i].name >> dept1[i].salary;
    }

    cout << "Enter the number of employees in Department 2: ";
    cin >> n2;
    Employee dept2[n2];
    cout << "Enter ID, Name, Salary for Department 2 employees:\n";
    for (int i = 0; i < n2; i++) {
        cin >> dept2[i].id >> dept2[i].name >> dept2[i].salary;
    }

    Employee merged[n1 + n2];
    for (int i = 0; i < n1; i++) merged[i] = dept1[i];
    for (int i = 0; i < n2; i++) merged[n1 + i] = dept2[i];

    mergeSort(merged, 0, n1 + n2 - 1);

    cout << "\nMerged and sorted employee records by ID:\n";
    for (int i = 0; i < n1 + n2; i++) {
        cout << merged[i].id << " " << merged[i].name << " " << merged[i].salary << endl;
    }

    return 0;
}
