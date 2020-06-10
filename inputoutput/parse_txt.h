#ifndef PARSE_TXT_H
#define PARSE_TXT_H

#include "../classes/maze/maze.h"

/*
    in: vector<vector<T>>
    This is a method mostly for debugging 
    Used to print the vector to the console to check if maze is parsed correctly
*/
template<class T>
void print_vector(std::vector<std::vector<T>> const ma);

/*  
    in: stream, std::vector<std::vector<char>>
    out: std::vector<std::vector<char>>
    parsing the maze data into a 2d vector
    takes line in from stream and adds it to a 2d vector
    returns a parsed 2d vector
*/
template <class T>
std::vector<std::vector<T>> maze_parse(std::istream& stream, std::vector<std::vector<T>> maze);

/*
    in: vector<vector<char>> 
    This is the method used to find the start and end coords
    Rules for this maze solving program is that the maze must have the start at the top and end at the bottom
    Obviously they can be swapped around, because it doesn't really matter, but thats the rule
*/
std::vector<std::pair<int,int>> find_coord(std::vector<std::vector<char>> maze);

/*
    in: stream, maze obj
    This is the main method of this file
    Main calls this method and then this works on its other methods
*/
void parse(std::istream& stream, Maze *maze);

#endif