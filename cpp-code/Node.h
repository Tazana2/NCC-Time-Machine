//
// Created by danis on 9/4/2023.
//

#ifndef MAQUINATIEMPO_NODE_H
#define MAQUINATIEMPO_NODE_H
#include "Data.h"

class Node {
protected:
    Data* data;
    Node* next;
    Node* prev;
public:
    Node(Data* data);
    Data* getData() const;
    // void setData(Data* data);
    Node* getNext() const;
    void setNext(Node* pNode);
    Node* getPrev() const;
    void setPrev(Node* pNode);
    std::string toString();
};


#endif //MAQUINATIEMPO_NODE_H
