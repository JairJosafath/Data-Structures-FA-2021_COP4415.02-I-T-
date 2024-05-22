//
// Created by jairj on 12/4/2021.
/*
File name: Stack.h
 Student name: Jair Josafath
 Section #2


 */
//
#include "Vertex.h"
#include <vector>
#ifndef PROJECT_5_STACK_H
#define PROJECT_5_STACK_H

class Stack {
private:
    std::vector<Vertex*> vertices;
    uint64_t capacity;
public:
    Stack(uint64_t capacity) {
        this->capacity = capacity;
        this->vertices.reserve(capacity);
    }

    bool push(Vertex* vertex) {
        if (vertices.size() >= capacity)
            return false;
        vertices.push_back(vertex);
        return true;
    }

    Vertex* pop() {
        if (vertices.empty())
            return nullptr;
        Vertex *v= vertices.back();
        vertices.pop_back();
        return v;
    }

    Vertex* top() {
        return vertices.back();
    }

    uint64_t size() {
        return vertices.size();
    }

    void print() {
        for (uint64_t i = 0; i < vertices.size(); i++) {
            std::cout << vertices.at(vertices.size() - i - 1)->getName();
            if (i == 0) std::cout << " <-- Top of stack";
            std::cout << std::endl;
        }
    }
};

#endif //PROJECT_5_STACK_H
