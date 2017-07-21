#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <vector>
#include "Book.h"

class Library {
    std::string name;
    std::vector<Book> books;
    int getIndex(int isbn);
    // FIXME fix function prototype for getBook
    Book& getBook(int isbn);
public:
    Library(std::string name);

    // accessors
    void setName(std::string name);
    std::string getName() const;

    void addBook(int isbn, std::string title, std::string author);
    void deleteBook(int isbn);

    std::string printBook(int isbn);
    std::string listBooks();

    // other methods / member functions
    void checkout(int isbn);
    void checkin(int isbn);
};

#endif

