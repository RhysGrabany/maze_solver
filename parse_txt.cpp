#include <iostream>
#include <vector>
#include <tuple>

#include "parse_txt.h"
#include "maze.h"
#include <boost/range/algorithm_ext/erase.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>



/*  
    in: stream std::vector<std::vector<char>>
    out: std::vector<std::vector<char>>
    parsing the maze data into a 2d vector
    takes line in from stream and adds it to a 2d vector
    returns a parsed 2d vector
*/
std::vector<std::vector<char>> maze_parse(std::istream& stream, std::vector<std::vector<char>> maze){

    std::string test;
    //stream.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

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
    in: string
    out: std::tuple<int, int>
    method for parsing the coords into an int tuple
    accepts a string and returns a tuple with two ints for the coords
*/
std::tuple<int, int> coords_parse(std::string unprse){

    boost::remove_erase_if(unprse, boost::is_any_of("()"));
    
    std::vector<std::string> str;
    boost::split(str, unprse, boost::is_any_of(","));

    return std::make_tuple(std::stoi(str[0]), std::stoi(str[1]));

}


/* 
    in: istream Maze
    method for parsing in the data from the text file
    goes through each line of the txt file and stores 
    them as strings before moving on and parsing them into 
    their respective data 

    coords will be placed into tuples and maze will be placed into a 2d vector
    all will be placed into a maze object
*/
void parse(std::istream& stream, Maze& maze){

    //height and width of the maze
    //start and end coords
    std::string width, height;
    std::string start, end;

    //stream input the data
    std::getline(stream, width);
    std::getline(stream, height);
    std::getline(stream, start);
    std::getline(stream, end);

    int wi = std::stoi(width);
    int he = std::stoi(height);


    std::vector<std::vector<char>> mazeprs(he, std::vector<char> (wi, 0));

    maze.setMaze(maze_parse(stream, mazeprs));
    maze.setStart(coords_parse(start));
    maze.setEnd(coords_parse(end));

}
