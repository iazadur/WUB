#include <stdio.h>

int main() {
    int n, i, grade, total = 0, high = 0, low = 100;
    float avg;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    int grades[n];

    // Input grades
    for (i = 0; i < n; i++) {
        printf("Enter grade for student %d: ", i + 1);
        scanf("%d", &grades[i]);
        total += grades[i];

        // Calculate highest and lowest grade
        if (grades[i] > high) high = grades[i];
        if (grades[i] < low) low = grades[i];
    }

    // Calculate average
    avg = (float) total / n;

    // Output
    printf("Class average: %.2f\n", avg);
    printf("Highest grade: %d\n", high);
    printf("Lowest grade: %d\n", low);

    return 0;
}
