//
// Created by danis on 9/6/2023.
//

#ifndef MAQUINATIEMPO_LIST_H
#define MAQUINATIEMPO_LIST_H
#include "Node.h"

class List {
protected:
    Node *head;
    Node *tail;
public:
    List();
    void add();
    void add(Node* node);
    void showList();
    Node* getHead() const;
    Node* getTail() const;
};


#endif //MAQUINATIEMPO_LIST_H
