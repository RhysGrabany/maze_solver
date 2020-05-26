#include <iostream>
#include <vector>
#include <tuple>

#include "parse_txt.h"
#include "maze.h"
#include <boost/range/algorithm_ext/erase.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>


// method for printing the 2d maze vector
template <class T>
void print_vector(std::vector<std::vector<char>> const ma){
    fflush(stdout);

    for(std::vector<T> row: ma){
        for(T val: row){
            std::cout << val;
        }
        std::cout << '\n';
    }

}

// parsing the maze data into a 2d vector
std::vector<std::vector<char>> maze_parse(std::istream& stream, std::vector<std::vector<char>> maze){

    std::string test;
    stream.ignore();

    int height = 0;
    while(std::getline(stream, test)){
        std::vector<char> line;
        
        for (int i = 0; i < test.length(); i++){
            line.push_back(test[i]);
        }
        
        maze.push_back(line);
        height++;
    }

    //print_vector(maze);
  
    return maze;
}

std::tuple<int, int> coords_parse(std::string unprse){

    boost::remove_erase_if(unprse, boost::is_any_of("()"));
    
    std::vector<std::string> str;
    boost::split(str, unprse, boost::is_any_of(","));

    return std::make_tuple(std::stoi(str[0]), std::stoi(str[1]));

}


// Method for parsing in the data from the text file
void parse(std::istream& stream, Maze maze){

    //height and width of the maze
    //start and end coords
    int width, height;
    std::string start, end;

    //stream input the data
    stream >> height >> width >> start >> end; 
    //std::cout << height << std::endl << width << std::endl << start << std::endl << end << std::endl;

    std::vector<std::vector<char>> mazeprs(width, std::vector<char> (height, 0));

    std::vector<std::vector<char>> mz = maze_parse(stream, mazeprs);

    print_vector(mz);



}
