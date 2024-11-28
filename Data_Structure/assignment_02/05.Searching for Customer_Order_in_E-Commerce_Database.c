#include <stdio.h>
#include <string.h>

// Define the Order structure
struct Order {
    int orderID;
    char customerName[50];
    float totalAmount;
};

// Function to find an order by orderID using binary search
void findOrderByID(struct Order orders[], int n, int orderID) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (orders[mid].orderID == orderID) {
            printf("Order ID: %d\nCustomer Name: %s\nTotal Amount: $%.2f\n", 
                    orders[mid].orderID, orders[mid].customerName, orders[mid].totalAmount);
            return;
        }
        else if (orders[mid].orderID < orderID) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    printf("Order not found.\n");
}

// Main function
int main() {
    // Array of orders sorted by orderID
    struct Order orders[] = {
        {1001, "Alice Johnson", 250.75},
        {1002, "Bob Smith", 150.00},
        {1003, "Carol Williams", 300.40}
    };

    // OrderID to search for
    int orderIDToSearch = 1002;
    findOrderByID(orders, 3, orderIDToSearch);  // Call search function
    return 0;
}
