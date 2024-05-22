#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Graph.h"

int main() {

//    Stack stack(5);
//    stack.push(new Vertex("A"));
//    stack.push(new Vertex("B"));
//    stack.push(new Vertex("C"));
//    stack.push(new Vertex("D"));
//    stack.push(new Vertex("E"));
//    stack.print();
//
//    Queue stack(5);
//    stack.enqueue(new Vertex("A"));
//    stack.enqueue(new Vertex("B"));
//    stack.enqueue(new Vertex("C"));
//    stack.enqueue(new Vertex("D"));
//    stack.enqueue(new Vertex("E"));
//    stack.print();
//    //std::vector

    Vertex *a = new Vertex("A"),
    *b= new Vertex("B"),
    *c= new Vertex("C"),
    *d= new Vertex("D");
    Edge *e1 = new Edge("e1",23,a,b),
            *e2 = new Edge("e2",5,b,d),
            *e3 = new Edge("e3",10,b,c),
            *e4 = new Edge("e4",78,a,c),
            *e5 = new Edge("e5",6,b,a),
            *e6 = new Edge("e6",28,c,a)
    ;
//    std::vector<Edge*> v;
//    v.push_back(e1);
    a->getEdges()->push_back(e1);
    a->getEdges()->push_back(e4);

    b->getEdges()->push_back(e3);
    b->getEdges()->push_back(e2);
    b->getEdges()->push_back(e5);

//
    c->getEdges()->push_back(e6);
//    c->getEdges()->push_back(e4);

   // d->getEdges()->push_back(e2);

//    a->print();
//    std::cout<<"-------\n";
//    b->print();
//    std::cout<<"-------\n";
//    c->print();
//    std::cout<<"-------\n";
//    d->print();
    auto *vertices = new std::vector<Vertex*>;
    vertices->push_back(a);
    vertices->push_back(b);
    vertices->push_back(c);
    vertices->push_back(d);

    auto *edges = new std::vector<Edge*>;
    edges->push_back(e1);
    edges->push_back(e2);
    edges->push_back(e3);
    edges->push_back(e4);
    Graph g(vertices,edges);
    g.printAdjecencyList();
    g.breadth1st();
    return 0;
}
