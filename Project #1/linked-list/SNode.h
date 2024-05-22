//
// Created by jairj on 10/10/2021.
//

#ifndef UNTITLED_SNODE_H
#define UNTITLED_SNODE_H

#include <iostream>

template<typename T>
class SNode {
    T data;
    SNode *next;

public:

    SNode() {
        data = 0;
        next = nullptr;
    }

    explicit SNode(T data) {
        this->data = data;
        next = nullptr;
    }

    SNode(T data, SNode<T>*next){
        this->data = data;
        this->next = next;
    }

    T getData() const {
        return data;
    }

    void setData(T data) {
        SNode::data = data;
    }

    SNode *getNext() const {
        return next;
    }

    void setNext(SNode *next) {
        SNode::next = next;
    }

    void print(){
        std::cout<<"{ data: "<< data<<" }"<<std::endl;
    }
};
#endif //UNTITLED_SNODE_H
