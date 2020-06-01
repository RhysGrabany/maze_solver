#ifndef FLOODFILL_H
#define FLOODFILL_H

#include "../../classes/maze/maze.h"

std::vector<std::vector<bool>> vis_vec(std::vector<std::vector<char>> maze);

int junction(std::pair<int, int> pos, std::vector<std::vector<char>> maze, std::vector<std::vector<bool>> vis);

// Print the current pair 
void printPair(std::pair<int, int> p);
  
// Print the Stack of Pairs 
void Showstack(std::stack<std::pair<int, int>> s);


std::vector<std::vector<char>> solve(std::pair<int, int> pos, std::pair<int, int> end,
    std::vector<std::vector<char>> maze);


void floodfill(Maze &ma);

#endif