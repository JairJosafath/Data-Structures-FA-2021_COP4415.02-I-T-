//
// Created by jairj on 12/4/2021.
/*
File name: Edge.h
 Student name: Jair Josafath
 Section #2


 */
//

#ifndef PROJECT_5_EDGE_H
#define PROJECT_5_EDGE_H

#include <string>
#include "Vertex.h"
class Vertex;//fix to the file not linking to the Vertex class.

class Edge
{

    std::string name;

    //vertex source is U
    Vertex *u;

    //vertex destination is V
    Vertex *v;

    uint64_t weight;

public:
    Edge(std::string name, uint64_t weight);

    Edge(std::string name, uint64_t weight, Vertex* u, Vertex* v);

    void print();

    const std::string &getName() const;

    void setName(const std::string &name);

    Vertex *getU() const;

    void setU(Vertex *u);

    Vertex *getV() const;

    void setV(Vertex *v);

    const uint64_t &getWeight() const;

    void setWeight(const uint64_t &weight);

};

#endif //PROJECT_5_EDGE_H
