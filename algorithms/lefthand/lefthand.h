#ifndef LEFTHAND_H
#define LEFTHAND_H

#include "../../classes/maze/maze.h"


std::vector<std::vector<char>> solve_iter(std::tuple<int, int> pos, std::tuple<int, int> end, 
    std::vector<std::vector<char>> maze);

std::vector<std::vector<char>> solve_recur(std::tuple<int, int> pos, std::tuple<int, int> end, 
    std::vector<std::vector<char>> maze);

void lefthand(Maze &ma);




#endif