//
// Created by Danis on 9/6/2023.
//
#include <iostream>
#include "List.h"
#include "Node.h"
#include "Data.h"

List::List() {
    this->head = nullptr;
    this->tail = nullptr;
}

Node *List::getHead() const {
    return this->head;
}

Node *List::getTail() const {
    return this->tail;
}

void List::add() {
    Node *node = new Node(new Data());

    if (this->head == nullptr) {
        this->head = node;
        this->tail = node;
    } else {
        this->tail->setNext(node);
        node->setPrev(this->tail);
        this->tail = node;
    }
}

void List::add(Node *node) {
    if (this->head == nullptr) {
        this->head = node;
        this->tail = node;
    } else {
        this->tail->setNext(node);
        node->setPrev(this->tail);
        this->tail = node;
    }
}

void List::showList() {
    if (this->head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node *node = this->head;
    while (node != nullptr) {
        std::cout << node->toString();
        node = node->getNext();
    }
}