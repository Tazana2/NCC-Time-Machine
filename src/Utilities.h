//
// Created by danis on 9/15/2023.
//

#ifndef MAQUINATIEMPO_UTILITIES_H
#define MAQUINATIEMPO_UTILITIES_H
#include "List.h"
#include "Node.h"
#include <vector>

using namespace std;

class Utilities {
public:
    static bool firstEventA;
    static bool firstEventB;
    static vector<Node> nodesEventA;
    static void searchForEventA(List* list);
    static void searchForEventB(List* list);
    static bool searchForEventC(List* list);

    static bool isCoPrime(int a, int b);
    static void countEvents(List* list);
    static void checkLastEvent(List* list);

};


#endif //MAQUINATIEMPO_UTILITIES_H
