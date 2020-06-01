#ifndef FLOODFILL_H
#define FLOODFILL_H

#include "../../classes/maze/maze.h"

std::vector<std::vector<std::pair<char, bool>>> vis_vec(std::vector<std::vector<char>> maze);


std::vector<std::vector<char>> solve(std::pair<int, int> pos, std::pair<int, int> end,
    std::vector<std::vector<char>> maze);


void floodfill(Maze &ma);

#endif