//
// Created by jairj on 10/10/2021.
//
#include "../linked-list/JLinkedList.h"
#include "iostream"

int main(){


    auto *list = new JLinkedList<uint16_t>;

    list->pushToBack(23);
    list->pushToBack(68);
    list->pushToBack(13);
    list->pushToFront(100);
    list->pushToBack(1343);

    list->clear();
    list->print();

    delete list;

    return 0;
}
