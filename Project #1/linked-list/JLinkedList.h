//
// Created by jairj on 10/10/2021.
//this class is the implementation of the doubly linked list that will be used
//

#ifndef UNTITLED_JLINKEDLIST_H
#define UNTITLED_JLINKEDLIST_H
#include <iostream>
#include "JNode.h"

template<typename T>

class JLinkedList{
    JNode<T> *head;
    JNode<T> *tail;
    uint64_t size;

public:
    JLinkedList(){
        head = tail = nullptr;
        size=0;
    }

    //some functions (CRUD) will return a bool value to verify if the operation has been completed
    bool clear(){
        auto *p=head;
        while(size){
            deleteNode(size--);
        }
        if(size)return false;
        return true;
    }
    bool pushToFront(T data){
        //if the list is empty write head and tail, if not add the new node
        if(!head) {
            tail = head = new JNode<T>(data);
            size++;
            return true;
        }

        auto *p = new JNode<T> (data, nullptr,head);

        head = p;

        if(p) {
            size++;
            return true;
        }

        return false;
    }

    bool pushToBack(T data){
        if(!head) {
            return pushToFront(data);
        }
        auto *p = new JNode<T> (data, tail, nullptr);
        tail->setNext(p);
        tail = p;

        if(p) {
            size++;
            return true;
        }

        return false;

    }

    //equivalent to updating a node
    bool insertAt(uint64_t index, T data){

        auto *p = nodeAt(index);
        if(p){
            p->setData(data);
            return true;
        }
        return false;
    }

    bool insertBefore(uint64_t index, T data){

        if(index==0) return pushToFront(data);
        auto *p = nodeAt(index);
        if(p){
            auto *q = new JNode<T>(data,p->getPrev(),p);
            p->getPrev()->setNext(q);
            p->setPrev(q);
            size++;
            return true;
        }
        return false;
    }

    bool insertAfter(uint64_t index, T data){
        if(index==size-1) return pushToBack(data);
        auto *p = nodeAt(index);
        if(p){
            auto *q = new JNode<T>(data,p,p->getNext());
            p->getNext()->setPrev(q);
            p->setNext(q);
            size++;
            return true;
        }
        return false;
    }

    //delete node at index
    bool deleteNode(uint64_t index){
        if(index==0){
            head = head->getNext();
            //head->setPrev(nullptr);
            delete head->getPrev();
            size--;
            return true;
        }
        if(index==size-1){
            tail = tail->getPrev();
            tail->setNext(nullptr);
            delete tail->getNext();
            size--;
            return true;
        }
        auto *p = nodeAt(index);
        if(p){
            p->getPrev()->setNext(p->getNext());
            p->getNext()->setPrev(p->getPrev());
            delete p;
            size--;
            return true;
        }
        return false;
    }

//returns the value of the node at given index
    T valueAt(uint64_t index){
        if(index==0)return head->getData();
        if(index==size-1)return tail->getData();
        if(index>=size) {
            throw std::runtime_error("out of bounds exception");

        }
        auto *p = head;
        for(uint64_t i = 0; i<index; i++) p=p->getNext();
        return p->getData();
    }
//returns node at given index
    JNode<T> *nodeAt(uint64_t index){
        if(index==0)return head;
        if(index==size-1)return tail;
        if(index>=size) {
            throw std::runtime_error("out of bounds exception");

        }
        auto *p = head;
        for(uint64_t i = 0; i<index; i++){
            p=p->getNext();
        }
        return p;
    }

    JNode<T> *getHead() const {
        return head;
    }

    void setHead(JNode<T> *head) {
        JLinkedList::head = head;
    }

    JNode<T> *getTail() const {
        return tail;
    }

    void setTail(JNode<T> *tail) {
        JLinkedList::tail = tail;
    }

    uint64_t getSize() const {
        return size;
    }

    void setSize(uint64_t size) {
        JLinkedList::size = size;
    }
//print function for the list
    void print(){
        JNode<T> *p = head;
        while(p){
            p->print();
            p = p->getNext();
        }
    }

    virtual ~JLinkedList() {
        auto p = head;
        while(p){
            if(p==tail){
                delete p;
                print();
                return;
            }
            p=p->getNext();
            delete p->getPrev();
        }
    }
};

#endif //UNTITLED_JLINKEDLIST_H
