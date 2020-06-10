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
    loc = "mazes/test.txt";

    Maze* maze = new Maze;

    in.open(loc);
    parse(in, maze);
    in.close();

    maze->printMaze();

    int choice;

    std::string save = "";

    choice = menu(true);
    switch(choice) {
        case 1 : lefthand(maze); save += "lefthand"; break;
        case 2 : righthand(maze); save += "righthand"; break;
        case 3 : floodfill(maze); save += "floodfill"; break;
    }

    //depthfirst(maze);

    save += (maze->getSolved()) ? "Solved.txt" : "NotSolved.txt";

    std::cout << save;


    choice = menu(false);
    std::vector<std::vector<char>> path = maze->getPath();

    switch(choice){
        case 1 : out(path, save); break;
        case 2 : break; 
    }

    delete maze;

    return 0;
}

