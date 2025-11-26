#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity;
};

void addBook() {
    struct Book b;
    FILE *fp = fopen("library.dat", "ab");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }
    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Book Title: ");
    getchar(); // Consume the newline character left by scanf
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0'; // Remove trailing newline
    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0'; // Remove trailing newline
    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);
    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
    printf("\nBook added successfully!\n");
}

void displayBooks() {
    struct Book b;
    FILE *fp = fopen("library.dat", "rb");
    if (!fp) {
        printf("\nNo books found.\n");
        return;
    }
    printf("\n---- All Books ----\n");
    while (fread(&b, sizeof(b), 1, fp)) {
        printf("\nID: %d", b.id);
        printf("\nTitle: %s", b.title);
        printf("\nAuthor: %s", b.author);
        printf("\nQuantity: %d", b.quantity);
        printf("\n---------------------\n");
    }
    fclose(fp);
}

void searchBook() {
    struct Book b;
    int id, found = 0;
    FILE *fp = fopen("library.dat", "rb");
    if (!fp) {
        printf("\nNo books available.\n");
        return;
    }
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);
    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n", b.id, b.title, b.author, b.quantity);
            found = 1;
            break;
        }
    }
    if (!found) printf("\nBook not found.\n");
    fclose(fp);
}

// New function to search by author
void searchBookByAuthor() {
    struct Book b;
    char authorName[100];
    int found = 0;
    FILE *fp = fopen("library.dat", "rb");
    if (!fp) {
        printf("\nNo books available.\n");
        return;
    }
    printf("\nEnter Author Name to search: ");
    getchar(); // Consume the newline character left by previous scanf
    fgets(authorName, sizeof(authorName), stdin);
    authorName[strcspn(authorName, "\n")] = '\0'; // Remove trailing newline

    printf("\n---- Books by %s ----\n", authorName);
    while (fread(&b, sizeof(b), 1, fp)) {
        if (strcmp(b.author, authorName) == 0) {
            printf("\nID: %d", b.id);
            printf("\nTitle: %s", b.title);
            printf("\nAuthor: %s", b.author);
            printf("\nQuantity: %d", b.quantity);
            printf("\n---------------------\n");
            found = 1;
        }
    }
    if (!found) printf("\nNo books found by author '%s'.\n", authorName);
    fclose(fp);
}

void deleteBook() {
    struct Book b;
    int id, found = 0;
    FILE *fp = fopen("library.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!fp) {
        printf("\nNo books to delete.\n");
        return;
    }
    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);
    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id != id) {
            fwrite(&b, sizeof(b), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("library.dat");
    rename("temp.dat", "library.dat");
    if (found) printf("\nBook deleted successfully!\n");
    else printf("\nBook not found.\n");
}

void updateBook() {
    struct Book b;
    int id, found = 0;
    FILE *fp = fopen("library.dat", "rb+");
    if (!fp) {
        printf("No books available.\n");
        return;
    }
    printf("\nEnter Book ID to update: ");
    scanf("%d", &id);
    while (fread(&b, sizeof(b), 1, fp)) {
        if (b.id == id) {
            found = 1;
            printf("\nEnter new title: ");
            getchar();
            fgets(b.title, sizeof(b.title), stdin);
            b.title[strcspn(b.title, "\n")] = '\0';
            printf("Enter new author: ");
            fgets(b.author, sizeof(b.author), stdin);
            b.author[strcspn(b.author, "\n")] = '\0';
            printf("Enter new quantity: ");
            scanf("%d", &b.quantity);
            fseek(fp, sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);
            printf("\nBook updated successfully!\n");
            break;
        }
    }
    if (!found) printf("\nBook not found.\n");
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\n====== Library Management System ======");
        printf("\n1. Add Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID"); // Changed text for clarity
        printf("\n4. Search Book by Author"); // New option
        printf("\n5. Delete Book");
        printf("\n6. Update Book");
        printf("\n7. Exit"); // Adjusted exit option number
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: searchBookByAuthor(); break; // Call the new function
            case 5: deleteBook(); break;
            case 6: updateBook(); break;
            case 7: exit(0); // Adjusted exit case
            default: printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
   }