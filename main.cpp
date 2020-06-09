#include <iostream>
#include <fstream>

#include "inputoutput/parse_txt.h"
#include "inputoutput/output.h"

#include "classes/maze/maze.h"

#include "algorithms/lefthand/lefthand.h"
#include "algorithms/righthand/righthand.h"
#include "algorithms/floodfill/floodfill.h"
#include "algorithms/depthfirst/depthfirst.h"

int menu(bool first){
    int choice;
    if(first){
        std::cout << "\nWhich maze solving algorithm would you like to use?\n" << 
            "1. Lefthand Algo (Keeps the wall on the left)\n" << 
            "2. Righthand Algo (Keeps the wall on the right)\n" << 
            "3. Floodfill Algo (Tries every possible route until solution is found).\n\n";
        
        std::cin >> choice;
        std::cout << "\n\n";
    } else {

        std::cout << "Would you like to output the path to file?\n" <<
            "1. Yes \t 2. No\n\n";
        
        std::cin >> choice;
    }

    return choice;
}

int main(){

    std::ifstream in;
    std::string loc;

    //std::cout << "Load a text file: \n";
    //std::cin >> loc;
    loc = "mazes/example2.txt";

    in.open(loc);

    Maze* maze = new Maze;

    parse(in, maze);
    in.close();

    int choice;

    /*choice = menu(true);
    switch(choice) {
        case 1 : lefthand(maze); break;
        case 2 : righthand(maze); break;
        case 3 : floodfill(maze); break;
    }*/

    depthfirst(maze);


    choice = menu(false);
    std::vector<std::vector<char>> path = maze->getPath();

    switch(choice){
        case 1 : out(path); break;
        case 2 : break; 
    }

    delete maze;

    return 0;
}

