//
// Created by jairj on 12/4/2021.
//

#include <iostream>
#include "Graph.h"
#include "Queue.h"
#include "Stack.h"

void Graph::shortestPathbetweenVertecisByWeight(Vertex* A, Vertex* B) {

}

//print the adjecency list
/*
 format
let source vertex=u and destination vertex=v1,v2,...,vn

 u:v1,v4,v5

 */
void Graph::printAdjecencyList() {
    std::cout<<"Adjecency list:\n";
    for(Vertex *v : *vertices){

        //check first if list is not empty
        if(!v->getEdges()->empty()){

            //print U name
            std::cout<<v->getName()<<": ";

            //ForEach loop through U's edges
            for(Edge *e:*v->getEdges()){

                //print V name
                std::cout<<e->getV()->getName();

                //add comma if there are more edges
                if (e!=v->getEdges()->back()){
                    std::cout<<", ";
                }
            }
            std::cout<<std::endl;
        }
    }

}

std::vector<Vertex*> Graph::adjecencyList(Vertex *vertex) {
    std::vector<Vertex*> q;

            //ForEach loop through U's edges
            for(Edge *e:*vertex->getEdges()){

                //enque V
                q.push_back(e->getV());

            }
    return q;

}

void Graph::breadth1st() {

    std::cout<<"Breadth First Search attempt"<<std::endl;
   bool *visited = new bool[vertices->size()];
   for(int i = 0; i< vertices->size();i++){
       visited[i]= false;
   }

   auto *que = new Queue(vertices->size());

   //visit first node and mark it visited
   auto *v= vertices->at(0);
   visited[0] = true;
   que->enqueue(v);

   while(!que->isEmpty()){
       //deque V and print
       v = que->first();
       std::cout<<v->getName()<<", ";
       que->dequeue();

       std::vector<Vertex*> adj = adjecencyList(v);

       for(int i = 1; i<adj.size();i++){

           if(!visited[i])
           {
               visited[i]= true;

               que->enqueue( adj.at(i-1));
               std::cout<<adj.at(i-1)->getName()<<", ";
           }
           i++;
       }
       adj.clear();
   }
}

void Graph::depth1st() {

}

void Graph::depth1stByWeight() {

}

Graph::Graph() {
    this->vertices=vertices;
    this->edges=edges;
}

Graph::Graph(std::vector<Vertex *> *vertices, std::vector<Edge *> *edges) {
    this->vertices=vertices;
    this->edges=edges;
}

std::vector<Vertex *> *Graph::getVertices() const {
    return vertices;
}

std::vector<Edge *> *Graph::getEdges() const {
    return edges;
}

