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
    std::string event;
public:
    List();
    void add();
    void showList();
    void searchForEvent();
};


#endif //MAQUINATIEMPO_LIST_H
