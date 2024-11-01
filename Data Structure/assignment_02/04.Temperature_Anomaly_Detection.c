#include <stdio.h>

// Function to detect a temperature anomaly
void detectAnomaly(int temperatures[], int n, int anomaly) {
    for (int i = 0; i < n; i++) {
        if (temperatures[i] == anomaly) {
            printf("Anomaly detected: %d\n", anomaly);
            return;
        }
    }
    printf("No anomaly detected.\n");
}

// Main function
int main() {
    // Array of hourly temperature readings
    int temperatures[] = {22, 25, 23, 30, 28, 22, 27, 29, 30, 26, 24, 23};
    
    // Anomaly temperature to search for
    int anomaly = 30;
    detectAnomaly(temperatures, 12, anomaly);  // Call detection function
    return 0;
}
