//
// Created by danis on 9/15/2023.
//
#include <iostream>
#include "Utilities.h"
#include "List.h"
#include "Node.h"
#include "Data.h"

using namespace std;

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
        if (list->getTail()->getData()->isPrime()) { //Entregar datos
            for (Node node : Utilities::nodesEventA) {
                if (list->getTail()->getData()->getScientist() == "Albert") {
                    cout << "Albert se entregó datos a si mismo" << endl;
                } else if (list->getTail()->getData()->getScientist() == "Rosen" && node.getData()->getScientist() == "Albert") {
                    cout << "Rosen entregó los datos a Albert" << endl;
                }
            }
        } else {
            for (Node node : Utilities::nodesEventA){ //Observar
                if (Utilities::isCoPrime(list->getTail()->getData()->getNum(), node.getData()->getNum())) {
                    if (list->getTail()->getData()->getScientist() == "Albert") {
                        cout << "Albert viajó pero solo pudo observar" << endl;
                    } else if (list->getTail()->getData()->getScientist() == "Rosen") {
                        cout << "Rosen viajó pero solo pudo observar" << endl;
                    }
                }
            }
        }
        return;
    }
    Utilities::searchForEventA(list);
    Utilities::searchForEventB(list);


}
void Utilities::countEvents(List* list) {
    int contadorA = 0;
    int contadorB = 0;
    Node* temp = list->getHead();
    while (temp != nullptr) {
        if (temp->getData()->getEvent() == "Event A") {
            contadorA++;
        } else if (temp->getData()->getEvent() == "Event B") {
            contadorB++;
        }
        temp = temp->getNext();
    }
    cout << "Eventos A: " << contadorA << endl;
    cout << "Eventos B: " << contadorB << endl;
}
