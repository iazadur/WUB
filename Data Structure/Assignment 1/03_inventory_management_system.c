#include <stdio.h>

int main() {
    int stock[5] = {0}, choice, product, quantity;

    do {
        printf("1. Add Stock\n2. Remove Stock\n3. Display Stock\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product number (0-4): ");
                scanf("%d", &product);
                printf("Enter quantity to add: ");
                scanf("%d", &quantity);
                stock[product] += quantity;
                break;
            case 2:
                printf("Enter product number (0-4): ");
                scanf("%d", &product);
                printf("Enter quantity to remove: ");
                scanf("%d", &quantity);
                if (stock[product] >= quantity) {
                    stock[product] -= quantity;
                } else {
                    printf("Not enough stock to remove.\n");
                }
                break;
            case 3:
                printf("Current stock levels:\n");
                for (int i = 0; i < 5; i++) {
                    printf("Product %d: %d\n", i, stock[i]);
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
