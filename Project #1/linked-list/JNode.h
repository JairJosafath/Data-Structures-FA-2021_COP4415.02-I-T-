//
// Created by jairj on 10/10/2021.
//this is the implementation of the node that will be used in the linked list
//

#ifndef UNTITLED_JNODE_H
#define UNTITLED_JNODE_H
#include<iostream>

template<typename T>

class JNode{
    T data;
    JNode *prev;
    JNode *next;

public:
    JNode(){
        data = 0;
        prev = next = nullptr;
    }

    explicit JNode(T data){
        this->data = data;
        prev = next = nullptr;
    }

    JNode(T data, JNode<T> *prev, JNode<T> *next){
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

    T getData() {
        return data;
    }

    void setData(T data) {
        JNode::data = data;
    }

    JNode *getPrev()  {
        return prev;
    }

    void setPrev(JNode *prev) {
        JNode::prev = prev;
    }

    JNode *getNext()  {
        return next;
    }

    void setNext(JNode *next) {
        JNode::next = next;
    }

    void print(){
        //std::cout<<"[data : "<<data<<" ]"<<std::endl;
    }

    virtual ~JNode() {
         prev= nullptr;
         next= nullptr;
    }
};


#endif //UNTITLED_JNODE_H
