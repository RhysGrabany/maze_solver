#include <iostream>
#include <fstream>

#include "parse_txt.h"
#include "maze.h"
//#include <boost/algorithm/string.hpp>

int main(){

    std::ifstream in;
    in.open("example.txt");

    Maze maze;

    parse(in, maze);
    in.close();

    return 0;
}

