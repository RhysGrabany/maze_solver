#include <iostream>
#include <vector>
#include <utility>

#include "parse_txt.h"
#include "../classes/maze/maze.h"
#include <boost/range/algorithm_ext/erase.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>




std::vector<std::vector<char>> maze_parse(std::istream& stream, std::vector<std::vector<char>> maze){

    std::string test;

    int height = 0;
    while(std::getline(stream, test)){
        if(!test.empty()){
            
            for (int i = 0; i < test.length(); i++){
                maze[height][i] = test[i];
            }
            
            height++;
        }
    }
  
    return maze;
}


/*
    This is sort of confusing due to how the data is used in the algos but-
    The start and end coord format when being parsed is as so (x,y) or (column, row)
    (0,0) is top left
    The reasoning is because moving right and left should affect the x-axis so it goes first
    but when looping through a vector it is the second variable so it is like (y,x)
    DO NOT MIX THESE UP
*/
std::vector<std::pair<int,int>> find_coord(std::vector<std::vector<char>> maze){

    std::vector<std::pair<int, int>> coords;

    std::vector<char>::iterator it;

    it = std::find(maze[0].begin(), maze[0].end(), ' ');

    long first = it - maze[0].begin();
    coords.push_back(std::make_pair(first, 0));

    it = std::find(maze[maze.size()-1].begin(), maze[maze.size()-1].end(), ' ');
    
    long sec = it - maze[maze.size()-1].begin();
    coords.push_back(std::make_pair(sec, maze.size()-1));


    return coords;

}


/* 
    in: istream Maze
    method for parsing in the data from the text file
    goes through each line of the txt file and stores 
    them as strings before moving on and parsing them into 
    their respective data 

    coords will be placed into pairs and maze will be placed into a 2d vector
    all will be placed into a maze object
*/
void parse(std::istream& stream, Maze *maze){

    //height and width of the maze
    //start and end coords
    std::string width, height;

    //stream input the data
    std::getline(stream, width);
    std::getline(stream, height);

    int wi = std::stoi(width);
    int he = std::stoi(height);


    std::vector<std::vector<char>> mazeprs(he, std::vector<char> (wi, 0));

    maze->setMaze(maze_parse(stream, mazeprs));

    std::vector<std::vector<char>> ma = maze->getMaze();
    std::vector<std::pair<int,int>> coords = find_coord(ma);

    std::cout << coords.size() << "\n";

    maze->setStart(coords[0]);
    maze->setEnd(coords[1]);

}
