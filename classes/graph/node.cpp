


#include "node.h"
#include <utility>

Node::Node(){}

Node::Node(int v, std::pair<int,int> co){
    vertice = v;
    coord = co;

}


void Node::setVertice(int v){
    vertice = v;
}

void Node::setCoord(std::pair<int,int> coo){
    coord = coo;
}

int Node::getVertice(){
    return vertice;
}

std::pair<int,int> Node::getCoord(){
    return coord;
}


