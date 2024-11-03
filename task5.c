#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int bookID;
    char title[100];
    char author[50];
    int year;
    float price;
} Book;


static Book books[1000];  
static int N = 0;         


void loadBookData();
void saveBookData();
void inputBookData();
void displayBookData();
void findBookByID();
void calculateTotalValue();
void displayMenu();

int main() {
    loadBookData();
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                inputBookData();
                break;
            case 2:
                displayBookData();
                break;
            case 3:
                findBookByID();
                break;
            case 4:
                calculateTotalValue();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add a book\n");
    printf("2. Display all books\n");
    printf("3. Search for a book by ID\n");
    printf("4. Calculate total value of books\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}


void loadBookData() {
    FILE *fp = fopen("books.dat", "rb");
    if (fp == NULL) {
        printf("No existing book data found.\n");
        return;
    }
    
    N = fread(books, sizeof(Book), 1000, fp);
    printf("%d books loaded successfully.\n", N);
    fclose(fp);
}

void saveBookData() {
    FILE *fp = fopen("books.dat", "wb");
    if (fp == NULL) {
        printf("Error: Unable to save book data!\n");
        return;
    }
    
    fwrite(books, sizeof(Book), N, fp);
    fclose(fp);
    printf("Book data saved successfully.\n");
}

void inputBookData() {
    if (N >= 1000) {
        printf("Error: Library is full!\n");
        return;
    }
    
    printf("\nEnter Book Details:\n");
    printf("Book ID: ");
    scanf("%d", &books[N].bookID);
    
    
    while (getchar() != '\n');
    
    printf("Title: ");
    fgets(books[N].title, sizeof(books[N].title), stdin);
    books[N].title[strcspn(books[N].title, "\n")] = 0; 
    
    printf("Author: ");
    fgets(books[N].author, sizeof(books[N].author), stdin);
    books[N].author[strcspn(books[N].author, "\n")] = 0;  
    
    printf("Year: ");
    scanf("%d", &books[N].year);
    
    printf("Price (SAR): ");
    scanf("%f", &books[N].price);
    
    N++;
    saveBookData();
}

void displayBookData() {
    if (N == 0) {
        printf("No books in the library.\n");
        return;
    }
    
    printf("\nLibrary Books:\n");
    printf("%s  %s  %s  %s  %s\n", "ID", "Title", "Author", "Year", "Price(SAR)");
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < N; i++) {
        printf("%d  %s  %s  %d   %.2f\n",
               books[i].bookID,
               books[i].title,
               books[i].author,
               books[i].year,
               books[i].price);
    }
}

void findBookByID() {
    int searchID;
    printf("Enter Book ID to search: ");
    scanf("%d", &searchID);
    
    for (int i = 0; i < N; i++) {
        if (books[i].bookID == searchID) {
            printf("\nBook found:\n");
            printf("ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            printf("Price: %.2f SAR\n", books[i].price);
            return;
        }
    }
    
    printf("Book with ID %d not found.\n", searchID);
}

void calculateTotalValue() {
    float total = 0;
    for (int i = 0; i < N; i++) {
        total += books[i].price;
    }
    printf("Total value of all books: %.2f SAR\n", total);
}
