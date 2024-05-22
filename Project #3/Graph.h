//
// Created by jairj on 12/4/2021.
/*
File name: Graph.h
 Student name: Jair Josafath
 Section #2


 */
//

#ifndef PROJECT_5_GRAPH_H
#define PROJECT_5_GRAPH_H

#include "Edge.h"
#include "Vertex.h"
#include "Queue.h"
#include <vector>

class Graph
{
    std:: vector<Vertex*> *vertices;
    std:: vector<Edge*> *edges;


public:
    Graph();
    Graph(std:: vector<Vertex*> *vertices,std:: vector<Edge*> *edges);
    void shortestPathbetweenVertecisByWeight(Vertex* A, Vertex* B);

    void printAdjecencyList();

    std::vector<Vertex*> adjecencyList(Vertex *v);

    void breadth1st();

    void depth1st();

    void depth1stByWeight();

    std::vector<Vertex *> *getVertices() const;

    std::vector<Edge *> *getEdges() const;
};
#endif //PROJECT_5_GRAPH_H
