
#include <ostream>
#include <sstream>
#include "Library.h"
using namespace std;

Library::Library(string name) : name(name) {}

// accessors
void Library::setName(string name) {
    this->name = name;
}
string Library::getName() const {
    return name; // or this->name
}

int Library::getIndex(int isbn) {
    for (int i = 0; i < books.size(); ++i) {
        Book book = books.at(i);
        if (books.at(i).getISBN() == isbn)
            return i; // exits immediately
    }
    throw runtime_error("Unknown ISBN number");
}

// FIXME
// update to return by reference
Book& Library::getBook(int isbn) {
    return books.at(getIndex(isbn));
}

void Library::addBook(int isbn, string title, string author) {
    books.push_back(Book(isbn, title, author));
}

void Library::deleteBook(int isbn) {
    books.erase(books.begin() + getIndex(isbn));
}

string Library::printBook(int isbn) {
    ostringstream oss;
    oss << "Book in " << name << ": " << endl;
    oss << books.at(getIndex(isbn)) << endl;
    return oss.str();
}

string Library::listBooks() {
    ostringstream oss;
    oss << "Books in " << name << ": " << endl;
    if (books.size() == 0) {
        oss << " - No Books in collection. -" << endl;
    }
    for (int i = 0; i < books.size(); ++i) {
        Book book = books.at(i);
        oss << books.at(i) << endl;
    }
    return oss.str();
}

void Library::checkout(int isbn) {
    getBook(isbn).checkout();
}

void Library::checkin(int isbn) {
    getBook(isbn).checkin();
}