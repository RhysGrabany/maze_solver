#include <iostream>
#include <fstream>

#include "inputoutput/parse_txt.h"
#include "classes/maze/maze.h"

#include "algorithms/lefthand/lefthand.h"
#include "algorithms/righthand/righthand.h"
#include "algorithms/floodfill/floodfill.h"

int menu(){
    std::cout << "\nWhich maze solving algorithm would you like to use?\n" << 
        "1. Lefthand Algo (Keeps the wall on the left)\n" << 
        "2. Righthand Algo (Keeps the wall on the right)\n" << 
        "3. Floodfill Algo (Tries every possible route until solution is found).\n\n";
    
    int choice;
    std::cin >> choice;
    std::cout << std::endl << std::endl;

    return choice;
}

int main(){

    std::ifstream in;
    in.open("mazes/example2.txt");

    Maze maze;

    parse(in, maze);
    in.close();

    int choice = menu();
    switch(choice) {
        case 1 : lefthand(maze); break;
        case 2 : righthand(maze); break;
        case 3 : floodfill(maze); break;
    }

    return 0;
}

