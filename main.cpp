#include <iostream>
#include <fstream>

#include "inputoutput/parse_txt.h"
#include "classes/maze/maze.h"

#include "algorithms/lefthand/lefthand.h"
#include "algorithms/righthand/righthand.h"
#include "algorithms/floodfill/floodfill.h"


int main(){

    std::ifstream in;
    in.open("mazes/example.txt");

    Maze maze;

    parse(in, maze);
    in.close();

    floodfill(maze);
    //lefthand(maze);

    return 0;
}

