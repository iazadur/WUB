#include <stdio.h>

int main() {
    int temp[7], i, total = 0, above_30 = 0, hot, cold;
    float average;

    // Input temperatures
    for (i = 0; i < 7; i++) {
        printf("Enter temperature for day %d: ", i + 1);
        scanf("%d", &temp[i]);
        total += temp[i];

        if (temp[i] > 30) above_30++;  // Count hot days
    }

    hot = temp[0];
    cold = temp[0];

    // Find hot and cold days
    for (i = 1; i < 7; i++) {
        if (temp[i] > hot) hot = temp[i];
        if (temp[i] < cold) cold = temp[i];
    }

    average = (float) total / 7;

    // Output
    printf("Average temperature: %.2f°C\n", average);
    printf("Hotest day temperature: %d°C\n", hot);
    printf("Coldest day temperature: %d°C\n", cold);
    printf("Days above 30°C: %d\n", above_30);

    return 0;
}

