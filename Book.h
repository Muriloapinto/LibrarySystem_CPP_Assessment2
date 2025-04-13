#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool availability;
    std::string dateAdd;

public:
    // Constructor
    Book();
    Book(std::string title, std::string author, std::string isbn, std::string dateAdd);

    // Setters
    void setBookDetails(std::string title, std::string author, std::string isbn, std::string dateAdd);
    
    // Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    bool isAvailable() const;
    std::string getDateAdd() const;
    
    // Methods required by the assessment
    void displayBookDetails() const;
    bool borrowBook();
    void returnBook();
    
    // Static method to sort book array by ISBN
    static void sortBookData(Book books[], int size);
};

#endif // BOOK_H