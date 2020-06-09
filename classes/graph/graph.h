#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"
#include <vector>


class Graph{

    private:
        int m_NoOfNodes;
        std::vector<Node*> m_Nodes;
        std::vector<std::vector<int>> m_AdjList;

    public:
        Graph();
        Graph(int noOfNodes, std::vector<Node*> nodes, std::vector<std::vector<int>> adj_list);

        void setNoOfNodes(int noOfEdges);
        void setNodes(std::vector<Node*> nodes);
        void setEdges(std::vector<std::vector<int>> adj_list);

        int getNoOfNodes();
        std::vector<Node*> getNodes();
        std::vector<std::vector<int>> getAdjList();

        void printAdjList();


};




#endif