#include "Book.h"
#include <iostream>
#include <algorithm>

// Default constructor
Book::Book() : title(""), author(""), isbn(""), availability(true), dateAdd("") {}

// Parameterized constructor
Book::Book(std::string title, std::string author, std::string isbn, std::string dateAdd) 
    : title(title), author(author), isbn(isbn), availability(true), dateAdd(dateAdd) {}

// Set book details
void Book::setBookDetails(std::string title, std::string author, std::string isbn, std::string dateAdd) {
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    this->dateAdd = dateAdd;
    this->availability = true;
}

// Display book details
void Book::displayBookDetails() const {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "ISBN: " << isbn << std::endl;
    std::cout << "Availability: " << (availability ? "Available" : "Borrowed") << std::endl;
    std::cout << "Date Added: " << dateAdd << std::endl;
    std::cout << "------------------------" << std::endl;
}

// Borrow book method
bool Book::borrowBook() {
    if (availability) {
        availability = false;
        return true;
    }
    return false;
}

// Return book method
void Book::returnBook() {
    availability = true;
}

// Getters
std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return isbn;
}

bool Book::isAvailable() const {
    return availability;
}

std::string Book::getDateAdd() const {
    return dateAdd;
}

// Sort books by ISBN
void Book::sortBookData(Book books[], int size) {
    // Using bubble sort for simplicity
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].getISBN() > books[j + 1].getISBN()) {
                // Swap books
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}