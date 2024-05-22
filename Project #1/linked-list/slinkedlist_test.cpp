//
// Created by jairj on 10/11/2021.
//
#include <iostream>
#include "../linked-list/SLinkedList.h"
int main(){

    auto *p = new SLinkedList<uint16_t>;
    p->pushToBack(23);
    p->pushToBack(12);
    p->pushToFront(7833);
    p->pushToBack(3);
    p->deleteNode(1);
    p->print();
    return 0 ;
}