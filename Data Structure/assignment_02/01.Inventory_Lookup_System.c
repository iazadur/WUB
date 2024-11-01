#include <stdio.h>
#include <string.h>

struct Product {
    int itemID;
    char name[50];
    int stock;
};

void lookupProduct(struct Product products[], int n, int itemID) {
    for (int i = 0; i < n; i++) {
        if (products[i].itemID == itemID) {
            printf("Product Name: %s, Stock Level: %d\n", products[i].name, products[i].stock);
            return;
        }
    }
    printf("Product not found.\n");
}

int main() {
    struct Product products[] = {
        {1, "Notebook", 50},
        {2, "Pen", 100}, 
        {3, "Pencil", 75}
    };
    int itemID = 2;
    lookupProduct(products, 3, itemID);
    return 0;
}
