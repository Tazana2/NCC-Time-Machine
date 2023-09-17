#include <iostream>
#include <random>
#include "List.h"
#include "Utilities.h"

using namespace std;
int main() {
    List *list = new List();

    /**
    list->add(new Node(new Data(2, "Albert"))); // Debe ser un evento A
    Utilities::checkLastEvent(list);
    list->showList();
    cout << endl;
    list->add(new Node(new Data(10, "Rosen")));
    Utilities::checkLastEvent(list);
    list->showList();
    cout << endl;
    list->add(new Node(new Data(5, "Rosen")));
    Utilities::checkLastEvent(list);
    list->showList();
    cout << endl;
    list->add(new Node(new Data(6, "Rosen")));
    Utilities::checkLastEvent(list);
    list->showList();
    cout << endl;
    list->add(new Node(new Data(12, "Albert")));
    Utilities::checkLastEvent(list);
    list->showList();
    cout << endl;
    list->add(new Node(new Data(13, "Rosen")));
    Utilities::checkLastEvent(list);
    list->showList();
    cout << endl;
    list->add(new Node(new Data(2, "Albert")));
    Utilities::checkLastEvent(list);
    list->showList();
    cout << endl;
    list->add(new Node(new Data(16, "Rosen")));
    Utilities::checkLastEvent(list);
    list->showList();
    cout << endl;
    list->add(new Node(new Data(17, "Albert")));
    Utilities::checkLastEvent(list);
    list->showList();
    cout << endl;
    **/
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(3, 22);
    int num = dist(mt);

    for (int i = 0; i < num; i++) {
        list->add();
        Utilities::checkLastEvent(list);
    }

    list->showList();
    cout << "Hubo " << num << " nodos en la lista" << endl;
    Utilities::countEvents(list);
    return 0;
}