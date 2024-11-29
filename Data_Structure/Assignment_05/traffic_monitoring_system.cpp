// traffic_monitoring_system
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main() {
    int n;
    cout << "Enter number of vehicle speeds: ";
    cin >> n;

    int speeds[n];
    cout << "Enter vehicle speeds:\n";
    for (int i = 0; i < n; i++)
        cin >> speeds[i];

    bubbleSort(speeds, n);

    cout << "\nSorted speeds:\n";
    for (int i = 0; i < n; i++)
        cout << speeds[i] << " ";
    cout << endl;

    return 0;
}
