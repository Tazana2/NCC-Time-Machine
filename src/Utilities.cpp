//
// Created by danis on 9/15/2023.
//
#include <iostream>
#include "Utilities.h"
#include "List.h"
#include "Node.h"
#include "Data.h"

using namespace std;

bool Utilities::eventA = false;
bool Utilities::eventB = false;
bool Utilities::eventC = false;
vector<Node> Utilities::nodesEventA;

bool Utilities::isCoPrime(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return (a == 1);
}

void Utilities::searchForEventA(List *list) {
    Node *tail = list->getTail();
    if (tail->getData()->isPrime() && tail->getData()->getScientist() == "Albert") {
        tail->getData()->setEvent("Event A");
        Utilities::nodesEventA.push_back(*tail);
        return;
    }
}

void Utilities::searchForEventB(List *list) {
    Node *tail = list->getTail();
    Node *temp = list->getTail()->getPrev();
    while (temp != nullptr) {
        if (temp->getData()->isPrime()) {
            if (temp->getData()->getEvent() == "Event A" && tail->getData()->isPrime()) {
                tail->getData()->setEvent("Event B");
                return;
            }
        }
        temp = temp->getPrev();
    }
}

bool Utilities::searchForEventC(List *list) {
    Node *tail = list->getTail();
    Node *temp = list->getTail()->getPrev();
    while (temp != nullptr) {
        if (temp->getData()->getEvent() == "Event B") {
            for (Node node : Utilities::nodesEventA) {
                if (Utilities::isCoPrime(tail->getData()->getNum(), node.getData()->getNum())) {
                    tail->getData()->setEvent("Event C");
                    return true;
                }
            }
        }
        temp = temp->getPrev();
    }
    return false;
}

void Utilities::checkLastEvent(List* list) {
    if (Utilities::searchForEventC(list)) {
        if (list->getTail()->getData()->isPrime()) {
            cout << "Hubo un evento C y además es primo: " << list->getTail()->toString() << endl;
        } else {
            cout << "Hubo un evento C pero el dato del nodo no es primo : " << list->getTail()->toString() << endl;
        }
        return;
    }
    Utilities::searchForEventA(list);
    Utilities::searchForEventB(list);

}