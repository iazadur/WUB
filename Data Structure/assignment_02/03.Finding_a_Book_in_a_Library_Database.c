#include <stdio.h>
#include <string.h>

// Define the Book structure
struct Book {
    int ISBN;
    char title[100];
    char author[50];
    int publicationYear;
};

// Function to find a book by ISBN using binary search
void findBookByISBN(struct Book books[], int n, int ISBN) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (books[mid].ISBN == ISBN) {
            printf("Title: %s, Author: %s, Publication Year: %d\n", books[mid].title, books[mid].author, books[mid].publicationYear);
            return;
        }
        else if (books[mid].ISBN < ISBN) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    printf("Book not found.\n");
}

// Main function
int main() {
    // Initialize book array (sorted by ISBN)
    struct Book books[] = {
        {1001, "The Great Gatsby", "F. Scott Fitzgerald", 1925},
        {1002, "To Kill a Mockingbird", "Harper Lee", 1960},
        {1003, "1984", "George Orwell", 1949}
    };
    
    // ISBN to search
    int isbnToSearch = 1002;
    findBookByISBN(books, 3, isbnToSearch);  // Call search function
    return 0;
}
 