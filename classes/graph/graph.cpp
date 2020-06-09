

#include "graph.h"
#include <vector>



Graph::Graph(){}

Graph::Graph(int noOfNodes, std::vector<Node*> nodes, std::vector<std::vector<int>> adj_list){
    m_NoOfNodes = noOfNodes;
    m_Nodes = nodes;
    m_AdjList = adj_list;

}

void Graph::setNoOfNodes(int noOfNodes){
    m_NoOfNodes = noOfNodes;
}

void Graph::setNodes(std::vector<Node*> nodes){
    m_Nodes = nodes;
}

void Graph::setEdges(std::vector<std::vector<int>> adj_list){
    m_AdjList = adj_list;
}

int Graph::getNoOfNodes(){
    return m_NoOfNodes;
}

std::vector<Node*> Graph::getNodes(){
    return m_Nodes;
}

std::vector<std::vector<int>> Graph::getAdjList(){
    return m_AdjList;
}

void Graph::printAdjList(){

}