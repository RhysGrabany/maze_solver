

#include "graph.h"
#include <vector>



Graph::Graph(){}

Graph::Graph(int noON, std::vector<Node> no, std::vector<std::vector<int>> adj){
    noOfNodes = noON;
    nodes = no;
    adj_list = adj;

}

void Graph::setNoOfNodes(int noON){
    noOfNodes = noON;
}

void Graph::setNodes(std::vector<Node> no){
    nodes = no;
}

void Graph::setEdges(std::vector<std::vector<int>> adj){
    adj_list = adj;
}

int Graph::getNoOfNodes(){
    return noOfNodes;
}

std::vector<Node> Graph::getNodes(){
    return nodes;
}

std::vector<std::vector<int>> Graph::getAdjList(){
    return adj_list;
}

void Graph::printAdjList(){

}