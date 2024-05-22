//
// Created by jairj on 10/10/2021.
//

#ifndef UNTITLED_SLINKEDLIST_H
#define UNTITLED_SLINKEDLIST_H

#include "SNode.h"
#include "../entity/Course.h"

template<typename T>

class SLinkedList{
    SNode<T> *head;
    SNode<T> *tail;
    uint64_t size;

public:
    SLinkedList(){
        head=tail= nullptr;
        size=0;
    }
    //some functions (CRUD) will return a bool value to verify if the operation has been completed
    bool pushToFront(T data){
        //if the list is empty write head and tail, if not add the new node
        if(!head) {
            tail = head = new SNode<T>(data);
            size++;
            return true;
        }

        auto *p = new SNode<T> (data,head);

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
        auto *p = new SNode<T> (data);
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
            auto *q = new SNode<T>(data,p);
            nodeAt(index-1)->setNext(q);
            size++;
            return true;
        }
        return false;
    }

    bool insertAfter(uint64_t index, T data){
        if(index==size-1) return pushToBack(data);
        auto *p = nodeAt(index);
        if(p){
            auto *q = new SNode<T>(data,p->getNext());
            p->setNext(q);
            size++;
            return true;
        }
        return false;
    }

    bool deleteNode(uint64_t index){
        if(index==0){
            auto *p=head;
            head = head->getNext();
            delete p;
            size--;
            return true;
        }
        if(index==size-1){
            auto *p = tail;
            tail = nodeAt(index-1);
            tail->setNext(nullptr);
            delete p;
            size--;
            return true;
        }
        auto *p = nodeAt(index);
        if(p){
            nodeAt(index-1)->setNext(p->getNext());
            delete p;
            size--;
            return true;
        }
        return false;
    }

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

    SNode<T> *nodeAt(uint64_t index){
        if(index==0)return head;
        if(index==size-1)return tail;
        if(index>=size) {
            throw std::runtime_error("out of bounds exception");

        }
        auto *p = head;
        for(uint64_t i = 0; i<index; i++)
        {
            p=p->getNext();
        }
        return p;
    }

    SNode<T> *getHead() const {
        return head;
    }

    void setHead(SNode<T> *head) {
        this->head = head;
    }

    SNode<T> *getTail() const {
        return tail;
    }

    void setTail(SNode<T> *tail) {
        this->tail = tail;
    }

    uint64_t getSize() const {
        return size;
    }

    void setSize(uint64_t size) {
        this->size = size;
    }

    void print(){
        SNode<T> *p = head;
        while(p){
            p->print();
            p = p->getNext();
        }
    }

    virtual ~SLinkedList() {
        auto p = head;
        while(p){
            if(p==tail){
                delete p;
                return;
            }
            p=p->getNext();
        }
    }
};
#endif //UNTITLED_SLINKEDLIST_H
