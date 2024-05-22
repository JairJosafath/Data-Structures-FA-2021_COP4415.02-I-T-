#include <iostream>
#include "../linked-list/JNode.h"

int main() {
    auto *prev = new JNode<uint16_t>(45);
    auto *next = new JNode<uint16_t> (12);

    auto *node = new JNode<uint16_t> (20, prev, next);

    node->getPrev()->print();
    node->print();
    node->getNext()->print();
    return 0;
}
