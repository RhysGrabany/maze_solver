#ifndef DEPTHFIRST_H
#define DEPTHFIRST_H

#include "../../classes/maze/maze.h"
#include "../../classes/graph/node.h"

#include <vector>


std::vector<std::vector<int>> adj_list();

std::vector<Node> node_list(std::vector<std::vector<char>> maze);

void depthfirst(Maze &ma);

#endif