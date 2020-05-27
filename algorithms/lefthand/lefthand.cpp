
#include "lefthand.h"
#include "../../classes/maze/maze.h"

#include <vector>
#include <tuple>
#include <iostream>


std::vector<std::vector<char>> solve(std::tuple<int, int> pos, std::tuple<int, int> end, 
    std::vector<std::vector<char>> maze){

        if(pos == end){
            return maze;
        
        } else {

            int xp = std::get<0>(pos);
            int yp = std::get<1>(pos);

            if(maze[yp][xp] == ' '){
                maze[yp][xp] = '*';
            }

            



            return maze;

        }

}


void lefthand(Maze &ma){

    std::tuple<int, int> start = ma.getStart();
    std::tuple<int, int> end = ma.getEnd();
    std::vector<std::vector<char>> maze = ma.getMaze();

    maze = solve(start, end, maze);

    ma.setMaze(maze);
    ma.printMaze();


}


