#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList() {
    // Implement this function
    this -> head = nullptr;
    this -> tail = nullptr;
}

LinkedList::~LinkedList() {
    this->clear();
}

LinkedList::LinkedList(const LinkedList& source)
{
    // Implement this function
    //*this = source;

    this->head = 0;               // calling list head
    Node* currentNode = source.head;  /*For temprory store of head of link list*/
    while (currentNode != 0)
    {
        this->insertAtEnd(currentNode->location, currentNode->year, currentNode->month, currentNode->temperature);
        currentNode = currentNode->next;
    }
}

void LinkedList::insertAtEnd(int location, int year, int month, double temperature)
{
    Node* temp = new Node;
    temp->location = location;
    temp->year = year;
    temp->month = month;
    temp->temperature = temperature;
    temp->next = 0;
    Node* curr = this->head;
    if (curr != nullptr)
    {
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
    else
    {
        this->head = temp;
    }
}


void LinkedList::insertBack(int location, int year, int month, double temperature) {
    Node* newNode = new Node(location, year, month, temperature);
    if (tail != nullptr)
        tail->next = newNode; // attach to list
    tail = newNode;
    if (head == nullptr) { // empty list
        head = newNode; // only node is both head and tail
    }
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
    // Implement this function
    if((this != &source))
    {
        this->clear();
        Node* temp = source.head;
        while(temp != nullptr)
        {
            this->insert(temp->location, temp->year, temp->month, temp->temperature);
            temp = temp->next;
        }
    }
    return *this;
}

double LinkedList::tempAverage(int location, int year1, int year2) const
{
    double sum = 0;
    int count = 0;
    Node* currentNode = head;
    while(currentNode != nullptr)
    {
        if((currentNode->location == location) && (currentNode->year >= year1)
           && (currentNode->year <= year2))
        {
            sum += currentNode->temperature;
            count++;
            // cout << "Node Location: " << currentNode->location <<"\nNode Year: " << currentNode->year << endl;
            // cout << "Node Month: " << currentNode->month << "\nNode Temperature: " << currentNode->temperature << endl;
        }
        currentNode = currentNode->next;
    }
    if(sum == 0)
    {
        return -99.99;
    } else {
        return sum/count;
    }
}

double LinkedList::tempMode(int location, int year1, int year2) const
{
    vector<int> tempVec;
    Node* currentNode = head;
    // puts all the temperatures in a vector
    while(currentNode != nullptr)
    {
        if((currentNode->location == location) && (currentNode->year >= year1)
               && (currentNode->year <= year2))
        {
            int tempVal = round(currentNode->temperature);
            tempVec.push_back(tempVal);
        }
        currentNode = currentNode->next;
    }
    if(tempVec.size() == 0)
    {
        return -99.99;
    }
    sort(tempVec.begin(), tempVec.end());
    double number = tempVec.at(0);
    double mode = number;
    int count = 1;
    int countMode = 1;
    for(unsigned int i = 0; i < tempVec.size(); i++)
    {
        if(tempVec.at(i) == number)
        {
            count++;
        }
        else
        {
            if(count > countMode)
            {
                countMode = count;
                mode = number;
            }
            count = 1;
            number = tempVec.at(i);
        }
    }
    return mode;
}
void LinkedList::insert(int location, int year, int month, double temperature)
{
    Node* newNode = new Node(location, year, month, temperature);
    // newNode->next = nullptr;
    Node* currentNode = head;
    // head->next = newNode;
    if((head == tail) && head == nullptr)
    {
        newNode->next = nullptr;
        head = newNode;
        return;
    }
    if (currentNode == head) {
        if (compare(currentNode, newNode))
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        else if (currentNode->next == nullptr)
        {
            newNode->next = nullptr;
            currentNode->next = newNode;
            tail = newNode;
            return;
        }
        else
        {
            goto nextloop;
        }
    }
    else
    {
        while(currentNode->next != nullptr)
        {
            nextloop:
            if(compare(currentNode->next, newNode))
            {
                newNode->next = currentNode->next;
                currentNode->next = newNode;
                return;
            }
            else
            {
                currentNode = currentNode->next;
            }
            if(currentNode->next == nullptr)
            {
                newNode->next = nullptr;
                currentNode->next = newNode;
                tail = newNode;
                return;
            }
        }
    }
}

bool LinkedList::compare(Node* currentNode, Node* newNode) const {
    if(currentNode->location > newNode->location)
    {
        return true;
    }
    else if(currentNode->location == newNode->location)
    {
        if(currentNode->year > newNode->year)
        {
            return true;
        }
        else if(currentNode->year == newNode->year)
        {
            if(currentNode->month > newNode->month)
            {
                return true;
            }
            else if(currentNode->month == newNode->month)
            {
                if(currentNode->temperature >= newNode->temperature)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void LinkedList::clear() {
    Node* current = head;
    while(current != nullptr)
    {
        Node * deletable = current;
        current = current->next;
        delete deletable;
    }
    head = nullptr;
    tail = nullptr;
    return;
}

void LinkedList::print() const {
    /* Do not modify this function */
    print(cout);
}

void LinkedList::print(ostream& os) const {
    /* Do not modify this function */
    os << *this;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
    Node* current = ll.head;

    while(current != nullptr)
    {
        os << current->location;
        os << " " << current->year;
        os << " " << current->month;
        os << " " << current->temperature << endl;
        current = current->next;
    }
    return os;
}
