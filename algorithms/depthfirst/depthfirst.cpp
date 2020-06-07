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

std::vector<Node> node_list(std::vector<std::vector<char>> maze){

    std::vector<Node*> nodes;
    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));

    int id = 0;

    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){

            // WALL PATH WALL
            if((maze[i][j] == '#') && (isPath(maze[i][j+1], visited[i][j+1]))){
                Node* node = new Node(id, std::make_pair(j+1, i));
                nodes.push_back(node);
                visited[i][j+1] = true;
                id++;
                delete node;
                continue;
            }
            







        }
    }


}

void depthfirst(Maze &ma){

    std::vector<std::vector<char>> maze = ma.getMaze();

    Graph graph;

    std::vector<Node> nodes = node_list(maze);






}