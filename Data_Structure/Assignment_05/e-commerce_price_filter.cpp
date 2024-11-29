#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of product prices: ";
    cin >> n;
    int prices[n];

    cout << "Enter the product prices:\n";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    quickSort(prices, 0, n - 1);

    cout << "\nPrices sorted in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cout << prices[i] << " ";
    }

    return 0;
}
