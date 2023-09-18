//
// Created by danis on 9/4/2023.
//

#include "Node.h"
#include "Data.h"


Node::Node() {
    this->data = nullptr;
    this->next = nullptr;
    this->prev = nullptr;
}

Node::Node(Data* data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

Data *Node::getData() const {
    return this->data;
}

Node *Node::getNext() const {
    return this->next;
}

void Node::setNext(Node *pNode) {
    this->next = pNode;
}

Node *Node::getPrev() const {
    return this->prev;
}

void Node::setPrev(Node *pNode) {
    this->prev = pNode;
}

std::string Node::toString() {
    if (this->data == nullptr) {
        return "null";
    } else if (this->next == nullptr) {
        return this->data->toString() + " -> null\n";
    }
    return this->data->toString()+" -> ";
}
