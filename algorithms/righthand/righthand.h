#ifndef RIGHTHAND_H
#define RIGHTHAND_H

#include "../../classes/maze/maze.h"



std::vector<std::vector<char>> solve_iterR(std::tuple<int, int> pos, std::tuple<int, int> end, 
    std::vector<std::vector<char>> maze);

std::vector<std::vector<char>> solve_recurR(std::tuple<int, int> pos, std::tuple<int, int> end, 
    std::vector<std::vector<char>> maze);

void righthand(Maze *ma);




#endif