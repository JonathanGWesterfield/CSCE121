#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <ostream>

class Book {
    int isbn;
    std::string title;
    std::string author;
    bool checkedOut;
public:
    Book(int isbn, std::string title, std::string author);
    // No default constructor since we want to pass in ISBN Number
    //   and not allow it to be changed

    // accessors
    int getISBN() const;

    void setTitle(std::string title);
    std::string getTitle() const;

    void setAuthor(std::string author);
    std::string getAuthor() const;

    bool isCheckedout() const;
    void checkout();
    void checkin();
};

std::ostream& operator<<(std::ostream& os, const Book& book);

#endif

