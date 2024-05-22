//
// Created by jairj on 10/11/2021.
//

#include <iostream>
#include "../linked-list/SNode.h"
int main(){

    auto *node = new SNode<uint16_t>(100);
    auto *node2 = new SNode<uint16_t>(78,node);
    node->print();
    node2->print();
    node2->getNext()->print();


    return 0;
}