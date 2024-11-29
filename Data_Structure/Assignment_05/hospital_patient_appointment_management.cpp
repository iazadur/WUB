// hospital_patient_appointment_management

#include <iostream>
using namespace std;

struct Patient {
    string name;
    int time;
};

void insertionSort(Patient arr[], int n) {
    for (int i = 1; i < n; i++) {
        Patient key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].time > key.time) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter number of patients: ";
    cin >> n;

    Patient patients[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter name and appointment time for patient " << i + 1 << ": ";
        cin >> patients[i].name >> patients[i].time;
    }

    insertionSort(patients, n);

    cout << "\nSorted patient appointments:\n";
    for (int i = 0; i < n; i++) {
        cout << patients[i].name << " - " << patients[i].time << endl;
    }

    return 0;
}
