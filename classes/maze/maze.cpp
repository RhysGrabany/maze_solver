
#include <iostream>
#include <vector>
#include <utility>

#include "maze.h"

//////////////////
// Constructors //
//////////////////
Maze::Maze(){};

Maze::Maze(std::vector<std::vector<char>> mz, std::pair<int, int> s_coords, std::pair<int, int> e__coords){
    m_Maze = mz;
    m_Start = s_coords;
    m_End = e__coords;
}

/*Maze::Maze(std::vector<std::vector<char>> mz, std::pair<int, int> s_coords, 
    std::pair<int, int> e__coords, std::vector<std::vector<char>> pa, bool so){
    m = mz;
    start = s_coords;
    end = e__coords;
    path = pa;
    solved = so;
}*/

Maze::Maze(const Maze &maze){
    m_Maze = maze.m_Maze;
    m_Start = maze.m_Start;
    m_End = maze.m_End;

}

///////////////////
///  Destructor ///
///////////////////
Maze::~Maze(){};

///////////////
//  Setters  //
///////////////

void Maze::setMaze(std::vector<std::vector<char>> mz){
    m_Maze = mz;
}

void Maze::setStart(std::pair<int, int> s_coords){
    m_Start = s_coords;
}

void Maze::setEnd(std::pair<int, int> e_coords){
    m_End = e_coords;
}

void Maze::setPath(std::vector<std::vector<char>> pa){
    m_Path = pa;
}

void Maze::setSolved(bool so){
    m_Solved = so;
}

///////////////
//  Getters  //
///////////////

std::vector<std::vector<char>> Maze::getMaze(){
    return m_Maze;
}

std::pair<int, int> Maze::getStart(){
    return m_Start;
}

std::pair<int, int> Maze::getEnd(){
    return m_End;
}

std::vector<std::vector<char>> Maze::getPath(){
    return m_Path;

}

bool Maze::getSolved(){
    return m_Solved;

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

    std::vector<std::vector<char>> ma = m_Maze;

    for(int i = 0; i < ma.size(); i++){
        for(int j = 0; j < ma[i].size(); j++){
            std::cout << "[" << i << "|" << j << "]" << ma[i][j];
            //std::cout << ma[i][j];
        }
        std::cout << '\n';
    }
    std::cout << "\n";
}

void Maze::printPath(){

    std::vector<std::vector<char>> ma = m_Path;

    for(int i = 0; i < ma.size(); i++){
        for(int j = 0; j < ma[i].size(); j++){
            //std::cout << "[" << i << "|" << j << "]" << ma[i][j];
            std::cout << ma[i][j];
        }
        std::cout << '\n';
    }
    std::cout << "\n";

}

