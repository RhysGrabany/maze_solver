
#include <iostream>
#include <vector>
#include <tuple>

#include "maze.h"

//////////////////
// Constructors //
//////////////////
Maze::Maze(){};

Maze::Maze(std::vector<std::vector<char>> mz, std::tuple<int, int> s_coords, std::tuple<int, int> e__coords){
    mzp = mz;
    start = s_coords;
    end = e__coords;
}

Maze::Maze(std::vector<std::vector<char>> mz, std::tuple<int, int> s_coords, 
    std::tuple<int, int> e__coords, std::vector<std::vector<char>> pa, bool so){
    mzp = mz;
    start = s_coords;
    end = e__coords;
    path = pa;
    solved = so;
}

///////////////////
///  Destructor ///
///////////////////
Maze::~Maze(){};

///////////////
//  Setters  //
///////////////

void Maze::setMaze(std::vector<std::vector<char>> mz){
    mzp = mz;
}

void Maze::setStart(std::tuple<int, int> s_coords){
    start = s_coords;
}

void Maze::setEnd(std::tuple<int, int> e_coords){
    end = e_coords;
}

void Maze::setPath(std::vector<std::vector<char>> pa){
    path = pa;
}

void Maze::setSolved(bool so){
    solved = so;
}

///////////////
//  Getters  //
///////////////

std::vector<std::vector<char>> Maze::getMaze(){
    return mzp;
}

std::tuple<int, int> Maze::getStart(){
    return start;
}

std::tuple<int, int> Maze::getEnd(){
    return end;
}

std::vector<std::vector<char>> Maze::getPath(){
    return path;

}

bool Maze::getSolved(){
    return solved;

}

////////////////
//   Methods  //
////////////////

/*  
    in: std::vector<std::vector<char>>
    method for printing the 2d maze vector
    takes in a 2d vector and prints each element 
*/
void Maze::printMaze(){

    std::vector<std::vector<char>> ma = mzp;

    for(int i = 0; i < ma.size(); i++){
        for(int j = 0; j < ma[i].size(); j++){
            //std::cout << "[" << i << "|" << j << "]" << ma[i][j];
            std::cout << ma[i][j];
        }
        std::cout << '\n';
    }


}

