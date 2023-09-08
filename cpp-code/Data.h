//
// Created by danis on 9/4/2023.
//

#ifndef MAQUINATIEMPO_DATA_H
#define MAQUINATIEMPO_DATA_H
#include <string>

class Data {
protected:
    int num;
    std::string scientist;
    std::string event;
public:
    Data();
    int getNum() const;
    std::string getScientist();
    std::string getEvent();
    void setNum(int num);
    void setScientist(std::string scientist);
    void setEvent(std::string event);
    std::string toString();

    bool isPrime() const;
};


#endif //MAQUINATIEMPO_DATA_H
