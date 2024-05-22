//
// Created by jairj on 12/4/2021.
//

#include <string>
#include <iostream>
#include "Vertex.h"

Vertex::Vertex() {
    this->name="";
    this->edges= new std::vector<Edge*>;

}

Vertex::Vertex(std::string name) {

    this->name=name;
    this->edges= new std::vector<Edge*>;
}

const std::string &Vertex::getName() const {
    return name;
}

std::vector<Edge *> *Vertex::getEdges() const {
    return edges;
}

void Vertex::setEdges(std::vector<Edge *> *edges) {
    Vertex::edges = edges;
}

void Vertex::print() {

    std::cout<<"vertex name: "<<name<<"\nlist of edges in detail:"<<std::endl;
    for(Edge *e: *edges){
        e->print();
    }
}
