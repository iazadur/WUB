#include <stdio.h>

int main() {
    int days, i, total = 0, threshold, expense;
    float avg;

    printf("Enter the number of days in the month: ");
    scanf("%d", &days);

    int expenses[days];

    printf("Enter the expense threshold: ");
    scanf("%d", &threshold);

    // Input expenses
    for (i = 0; i < days; i++) {
        printf("Enter expense for day %d: ", i + 1);
        scanf("%d", &expenses[i]);
        total += expenses[i];

        if (expenses[i] > threshold) {
            printf("Day %d exceeds threshold!\n", i + 1);
        }
    }

    // Calculate Average
    avg = (float) total / days;

    // Output
    printf("Total expenses: %d\n", total);
    printf("Average expense: %.2f\n", avg);

    return 0;
}
