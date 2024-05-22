//
// Created by jairj on 12/4/2021.
//

#include <iostream>
#include "Edge.h"

Edge::Edge(std::string name, uint64_t weight) {
    this->name=name;
    this->weight=weight;

}

Edge::Edge(std::string name, uint64_t weight, Vertex *u, Vertex *v) {
    this->name=name;
    this->weight=weight;
    this->u=u;
    this->v=v;
}

const std::string &Edge::getName() const {
    return name;
}

void Edge::setName(const std::string &name) {
    Edge::name = name;
}

Vertex *Edge::getU() const {
    return u;
}

void Edge::setU(Vertex *u) {
    Edge::u = u;
}

Vertex *Edge::getV() const {
    return v;
}

void Edge::setV(Vertex *v) {
    Edge::v = v;
}

const uint64_t &Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(const uint64_t &weight) {
    Edge::weight = weight;
}

void Edge::print() {

    std::cout<<"edge: "<<name<<"\nweight: "<<weight<<std::endl;
    std::cout<<"from vertex: "<<u->getName()<<" to vertex: "<<v->getName()<<std::endl;
}


