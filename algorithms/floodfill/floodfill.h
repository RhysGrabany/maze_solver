#ifndef FLOODFILL_H
#define FLOODFILL_H

#include "../../classes/maze/maze.h"
#include <stack>

/*
    in: std::pair<int, int> pos, std::vector<std::vector<char>> maze, std::vector<std::vector<bool>> vis
    Takes in the currect position on the maze and checks each direction around it
    each potential route is added to a counter for how may junction paths is possible
    returns the counter of junctions
    out: int juncs

*/
int junction(std::pair<int, int> pos, std::vector<std::vector<char>> maze, 
    std::vector<std::vector<bool>> vis);

/*
    in: std::stack<std::pair<int,int> path, std::stack<std::pair<int, int> junctions
    Takes in the two stacks takes out the coords in the path stack that have been deadends
    this makes a smaller stack 
    out: std::stack<std::pair<int,int>> path
*/
std::stack<std::pair<int, int>> path_del(std::stack<std::pair<int,int>> path, 
    std::stack<std::pair<int,int>> junctions);

/*
    in: std::vector<std::vector<char>> maze, std::stack<std::pair<int, int>> path
    Takes in the maze vector and path stack, each coord in the stack is popped and added to the vector
    out: std::vector<std::vector<char>> maze
*/
std::vector<std::vector<char>> plot_maze(std::vector<std::vector<char>> maze, 
    std::stack<std::pair<int, int>> path);

/*
    in: std::pair<int,int> pos, std::pair<int,int> end, std::vector<std::vector<char>> maze
    Takes in the current position on the maze and the desired end point
    out: std::stack<std::pair<int,int>> path
*/
std::stack<std::pair<int,int>> solve(std::pair<int, int> pos, std::pair<int, int> end,
    std::vector<std::vector<char>> maze);

/*
    in: Maze ma
    This is the main method of this algo
    The goal of this algo is to test every possible junction looking for the exit
*/
void floodfill(Maze *ma);

#endif