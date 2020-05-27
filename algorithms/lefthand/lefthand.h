#ifndef LEFTHAND_H
#define LEFTHAND_H

#include "../../classes/maze/maze.h"

#include <vector>


std::vector<std::vector<char>> solve(std::tuple<int, int> pos, std::tuple<int, int> end, 
    std::vector<std::vector<char>> maze);

void lefthand(Maze &ma);




#endif