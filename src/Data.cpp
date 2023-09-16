//
// Created by danis on 9/4/2023.
//
#include <iostream>
#include <utility>
#include <random>
#include "Data.h"

using namespace std;

Data::Data() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> numDist(1, 100);
    std::uniform_int_distribution<int> scientistDist(1, 2);
    if (scientistDist(mt) == 1) {
        this->scientist = "Albert";
    } else {
        this->scientist = "Rosen";
    }
    this->num = numDist(mt);
    this->event = "Event N";
}

Data::Data(int num, std::string scientist) {
    this->num = num;
    this->scientist = std::move(scientist);
    this->event = "Event N";
}

int Data::getNum() const {
    return this->num;
}

std::string Data::getScientist() {
    return this->scientist;
}

std::string Data::getEvent() {
    return this->event;
}

void Data::setNum(int i) {
    this->num = i;
}

void Data::setScientist(std::string i) {
    this->scientist = std::move(i);
}

void Data::setEvent(std::string i) {
    this->event = std::move(i);
}

std::string Data::toString() {
    return "(" + this->scientist + "|" + std::to_string(this->num) + "|" + this->event + ")";
}

bool Data::isPrime() const {
    if (this->num == 1) {
        return false;
    }
    for (int i = 2; i < this->num; i++) {
        if (this->num % i == 0) {
            return false;
        }
    }
    return true;
}