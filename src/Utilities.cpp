//
// Created by danis on 9/15/2023.
//
#include <iostream>
#include "Utilities.h"
#include "List.h"
#include "Node.h"
#include "Data.h"
#include "string"

using namespace std;

bool Utilities::firstEventA = true;
bool Utilities::firstEventB = true;
vector<Node> Utilities::nodesEventA;

bool Utilities::isCoPrime(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return (a == 1);
}

void Utilities::countEvents(List* list) {
    int contadorA = 0, contadorB = 0;
    Node* temp = list->getHead();
    while (temp != nullptr) {
        contadorA += (temp->getData()->getEvent() == "Event A");
        contadorB += (temp->getData()->getEvent() == "Event B");
        temp = temp->getNext();
    }
    cout << "Eventos A: " << contadorA << endl;
    cout << "Eventos B: " << contadorB << endl;
}

void Utilities::searchForEventA(List *list) {
    Node *tail = list->getTail();
    if (Utilities::firstEventA) {
        if (tail->getData()->isPrime() && tail->getData()->getScientist() == "Albert") {
            tail->getData()->setEvent("Event A");
            Utilities::nodesEventA.push_back(*tail);
            Utilities::firstEventA = false;
            return;
        }
    } else if (tail->getData()->getEvent() == "Event B") {
        return;
    } else {
        Node *temp = list->getTail()->getPrev();
        while (temp != nullptr) {
            if (temp->getData()->getEvent() == "Event C" && tail->getData()->isPrime() && tail->getData()->getScientist() == "Albert") {
                if (tail->getData()->isPrime() && tail->getData()->getScientist() == "Albert") {
                    tail->getData()->setEvent("Event A");
                    Utilities::nodesEventA.push_back(*tail);
                    Utilities::firstEventA = false;
                    return;
                }
            }
            temp = temp->getPrev();
        }
    }
}

void Utilities::searchForEventB(List *list) {
    Node *tail = list->getTail();
    Node *temp = list->getTail()->getPrev();
    if (Utilities::firstEventB) {
        while (temp != nullptr) {
            if (temp->getData()->getEvent() == "Event A" && tail->getData()->isPrime()) {
                tail->getData()->setEvent("Event B");
                Utilities::firstEventB = false;
                return;
            }
            temp = temp->getPrev();
        }
    } else {
        while (temp != nullptr) {
            if (temp->getData()->getEvent() == "Event A" && tail->getData()->isPrime()) {
                tail->getData()->setEvent("Event B");
                return;
            } else if (temp->getData()->getEvent() == "Event C") {
                return;
            }
            temp = temp->getPrev();
        }
    }
}

bool Utilities::searchForEventC(List *list) {
    Node *nodeB = nullptr;
    Node *nodeC = nullptr;
    Node *tail = list->getTail();
    Node *temp = list->getTail()->getPrev();
    vector<Node> nodesEventACopy = Utilities::nodesEventA;
    while (temp != nullptr) {
        if (temp->getData()->getEvent() == "Event B") {
            nodeB = temp;
            for (auto it = nodesEventACopy.begin(); it != nodesEventACopy.end(); ++it) {
                Node *nodeA = &(*it);
                if (Utilities::isCoPrime(tail->getData()->getNum(), nodeA->getData()->getNum())) {
                    nodeC = tail;
                    tail->getData()->setEvent("Event C");
                    nodesEventACopy.erase(it);
                    if (nodeA != nullptr && nodeB != nullptr && nodeC != nullptr) {
                        cout << "Ocurrio una singularidad con los nodos: " << endl;
                        cout << nodeA->toString2() << " -> " << nodeB->toString2() << nodeC->toString2() << "\n" << endl;
                    }
                    return true;
                }
            }
        } else if (temp->getData()->getEvent() == "Event C") {
            return false;
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
                    cout << "Albert se entrego datos a si mismo" << "\n" << endl;
                    return;
                } else if (list->getTail()->getData()->getScientist() == "Rosen" && node.getData()->getScientist() == "Albert") {
                    cout << "Rosen entrego los datos a Albert" << "\n" << endl;
                    return;
                }
            }
        } else {
            for (Node node : Utilities::nodesEventA){ //Observar
                if (Utilities::isCoPrime(list->getTail()->getData()->getNum(), node.getData()->getNum())) {
                    if (list->getTail()->getData()->getScientist() == "Albert") {
                        cout << "Albert viajo pero solo pudo observar" << "\n" << endl;
                        return;
                    } else if (list->getTail()->getData()->getScientist() == "Rosen") {
                        cout << "Rosen viajo pero solo pudo observar" << "\n" << endl;
                        return;
                    }
                }
            }
        }
        return;
    }
    Utilities::searchForEventB(list);
    Utilities::searchForEventA(list);

}