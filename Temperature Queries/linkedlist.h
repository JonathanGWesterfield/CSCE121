#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include "node.h"

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Default constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Copy constructor
    LinkedList(const LinkedList& other);

    // Assignment constructor
    LinkedList& operator=(const LinkedList& other);

    // Insert a record to the linked list
    void insert(int location, int year, int month, double temperature);

    // Clear the content of this linked list
    void clear();
    void insertBack(int location, int year, int month, double temperature);
    void insertAtEnd(int location, int year, int month, double temperature);

    friend std::ostream& operator<<(std::ostream&, const LinkedList&);
    // Finds the average temperature in the range of years given
    double tempAverage(int location, int year1, int year2) const;
    // Finds the mode of the temperatures in the range of the years given
    double tempMode(int location, int year1, int year2) const;

    // The functions below are written already. Do not modify them.
    void print() const;
    void print(std::ostream&) const;
    bool compare(Node* currNode, Node* newNode) const;

};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
#endif
