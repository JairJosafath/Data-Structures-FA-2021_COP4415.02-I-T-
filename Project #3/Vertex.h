//
// Created by jairj on 12/4/2021.
/*
File name: Vertex.h
 Student name: Jair Josafath
 Section #2


 */
//

#ifndef PROJECT_5_VERTEX_H
#define PROJECT_5_VERTEX_H

#include "Edge.h"
#include <vector>

class Edge;//patch to use the class Edge in this class
class Vertex
{
    std::string name;

    //vector with ptrs to the edges to the vertices, these will be the V values of the Edge. see the Edge class for more details
    std::vector<Edge *> *edges;

public:
    Vertex();
    Vertex(std::string name);

    const std::string &getName() const;

    std::vector<Edge *> *getEdges() const;

    void setEdges(std::vector<Edge *> *edges);

    void print();

};
#endif //PROJECT_5_VERTEX_H
