#include "Book.h"
using namespace std;

Book::Book(int isbn, string title, string author) :
        isbn(isbn), title(title), author(author), checkedOut(false) {}

int Book::getISBN() const {
    return isbn;
}

void Book::setTitle(string title) {
    this->title = title;
}

string Book::getTitle() const {
    return title;
}

void Book::setAuthor(string author) {
    this->author = author;
}
string Book::getAuthor() const {
    return author;
}


bool Book::isCheckedout() const {
    return checkedOut;
}

void Book::checkout() {
    if (checkedOut)
        throw new runtime_error("Book already checked out");
    checkedOut = true;
}

void Book::checkin() {
    // no exception if we have book, then it is checked in
    checkedOut = false;
}


ostream& operator<<(ostream& os, const Book& book) {
    os << " - ISBN: " << book.getISBN() << endl;
    os << " - Title: " << book.getTitle() << endl;
    os << " - Author: " << book.getAuthor() << endl;
    os << " - Checked Out: " << boolalpha << book.isCheckedout() << endl;
    return os;
}