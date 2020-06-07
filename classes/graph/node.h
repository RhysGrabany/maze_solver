#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <utility>

class Node{

    private:
        int vertice = 0;
        std::pair<int,int> coord;
    public:
        Node();
        Node(int v, std::pair<int,int> coo);

        void setVertice(int v);
        void setCoord(std::pair<int,int> coo);

        int getVertice();
        std::pair<int,int> getCoord();


};

#endif