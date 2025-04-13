#include <iostream>
#include <string>
#include "Book.h"

int main() {
    const int LIBRARY_SIZE = 5;
    Book library[LIBRARY_SIZE];
    
    // Initialize the library with 5 sample books
    library[0].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", "2022-01-15");
    library[1].setBookDetails("To Kill a Mockingbird", "Harper Lee", "9780061120084", "2022-02-20");
    library[2].setBookDetails("1984", "George Orwell", "9780451524935", "2022-03-10");
    library[3].setBookDetails("Pride and Prejudice", "Jane Austen", "9780141439518", "2022-04-05");
    library[4].setBookDetails("The Hobbit", "J.R.R. Tolkien", "9780547928227", "2022-05-12");
    
    // Sort books by ISBN
    Book::sortBookData(library, LIBRARY_SIZE);
    
    std::string isbnInput;
    bool running = true;
    
    while (running) {
        // Display all books in the library
        std::cout << "\n==== Library Book Catalog ====" << std::endl;
        for (int i = 0; i < LIBRARY_SIZE; i++) {
            library[i].displayBookDetails();
        }
        
        // Prompt user for ISBN
        std::cout << "\nEnter the ISBN of the book you want to borrow (or '0' to exit): ";
        std::cin >> isbnInput;
        
        // Check if user wants to exit
        if (isbnInput == "0") {
            std::cout << "Thank you for using the Library Management System. Goodbye!" << std::endl;
            running = false;
            continue;
        }
        
        // Search for the book by ISBN
        bool bookFound = false;
        for (int i = 0; i < LIBRARY_SIZE; i++) {
            if (library[i].getISBN() == isbnInput) {
                bookFound = true;
                // Check if book is available
                if (library[i].isAvailable()) {
                    // Borrow the book
                    library[i].borrowBook();
                    std::cout << "You have successfully borrowed: " << library[i].getTitle() << std::endl;
                } else {
                    std::cout << "Sorry, this book is already borrowed." << std::endl;
                }
                break;
            }
        }
        
        // Book not found message
        if (!bookFound) {
            std::cout << "Book with ISBN " << isbnInput << " was not found in the library." << std::endl;
        }
    }
    
    return 0;
}