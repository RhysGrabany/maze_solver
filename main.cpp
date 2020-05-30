#include <iostream>
#include <fstream>

#include "inputoutput/parse_txt.h"
#include "classes/maze/maze.h"
#include "algorithms/lefthand/lefthand.h"
#include "algorithms/righthand/righthand.h"

int main(){

    std::ifstream in;
    in.open("mazes/example.txt");

    Maze maze;

    parse(in, maze);
    in.close();

    lefthand(maze);

    return 0;
}

