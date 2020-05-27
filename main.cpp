#include <iostream>
#include <fstream>

#include "inputoutput/parse_txt.h"
#include "classes/maze/maze.h"

int main(){

    std::ifstream in;
    in.open("example.txt");

    Maze maze;

    parse(in, maze);
    in.close();



    return 0;
}

