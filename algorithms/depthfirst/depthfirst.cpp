#include "depthfirst.h"
#include "../../classes/graph/node.h"
#include "../../classes/graph/graph.h"
#include "../../classes/maze/maze.h"

#include <vector>

std::vector<std::vector<int>> adj_list(){


}

bool isPath(char maze, bool visited){
    if((maze == ' ') && (visited = false)){
        return true;
    }
    return false;
}

std::vector<Node*> node_list(std::vector<std::vector<char>> maze){

    std::vector<Node*> nodes;
    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));

    int id = 0;

    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){

            if(maze[i][j] == ' '){

                Node *node = new Node(id, std::make_pair(j, i));
                nodes.push_back(node);
                id++;
                delete node;







                continue;

            }

        }
    }

    return nodes;


}

void depthfirst(Maze *ma){

    std::vector<std::vector<char>> maze = ma->getMaze();

    Graph *graph = new Graph;

    std::vector<Node*> nodes = node_list(maze);
    graph->setNodes(nodes);

    std::cout << nodes.size();

    delete graph;






}