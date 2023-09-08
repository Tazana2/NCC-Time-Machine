#include <iostream>
#include <random>
#include "List.h"

using namespace std;
int main() {
    List *list = new List();

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(3, 22);

    for (int i = 0; i < dist(mt); i++) {
        list->add();
        list->searchForEvent();
    }
    list->showList();
    cout << "Vainas de la vida beibi" << endl;
    return 0;
}