//
// Created by jairj on 12/4/2021.
/*
File name: Queue.h
 Student name: Jair Josafath
 Section #2


 */
//

#ifndef PROJECT_5_QUEUE_H
#define PROJECT_5_QUEUE_H
#include "Vertex.h"

class Queue {
private:
    std::vector<Vertex*> vertices;
    uint64_t capacity;
public:
    Queue(uint64_t capacity) {
        this->capacity = capacity;
        vertices.reserve(capacity);
    }

    bool enqueue(Vertex *vertex) {
        if (vertices.size() >= capacity)
            return false;
        this->vertices.push_back(vertex);
        return true;
    }

    Vertex* dequeue() {
        if (vertices.empty())
            return nullptr;
        Vertex *v = vertices.front();
        vertices.erase(vertices.begin());
        return v;
    }

    Vertex* first() {
        return vertices.back();
    }

    uint64_t size(){
        return vertices.size();
    }

    bool isEmpty(){
        return vertices.empty();
    }

    void print() {
        for (uint64_t i = 0; i < vertices.size(); i++) {
            std::cout << vertices.at(i)->getName();
            if (i == 0) std::cout << " <-- front";
            std::cout << std::endl;
        }
    }
};
#endif //PROJECT_5_QUEUE_H
