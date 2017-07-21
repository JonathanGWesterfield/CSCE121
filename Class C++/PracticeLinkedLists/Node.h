//
// Created by Jonathan G. Westerfield on 11/3/16.
//

#ifndef PRACTICE_LINKED_LIST_NODE_H
#define PRACTICE_LINKED_LIST_NODE_H

struct Node
{
    int value;
    Node* next;
    Node(int value) : value(value), next(nullptr) {}
    Node() : value(0), next(nullptr){}
};

#endif //PRACTICE_LINKED_LIST_NODE_H
