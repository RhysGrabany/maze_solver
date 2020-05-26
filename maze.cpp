
#include <iostream>
#include <vector>
#include <tuple>

#include "maze.h"

Maze::Maze(){};

Maze::Maze(std::vector<std::vector<char>> mz, std::tuple<int, int> s_coords, std::tuple<int, int> e__coords){
    mzp = mz;
    start = s_coords;
    end = e__coords;
}

void Maze::setMaze(std::vector<std::vector<char>> mz){
    mzp = mz;
}

void Maze::setStart(std::tuple<int, int> s_coords){
    start = s_coords;
}

void Maze::setEnd(std::tuple<int, int> e_coords){
    end = e_coords;
}

std::vector<std::vector<char>> Maze::getMaze(){
    return mzp;
}



