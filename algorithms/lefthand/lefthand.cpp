
#include "lefthand.h"
#include "../../classes/maze/maze.h"

#include <vector>
#include <tuple>
#include <iostream>


std::vector<std::vector<char>> solve(std::tuple<int, int> pos, std::tuple<int, int> end, 
    std::vector<std::vector<char>> maze){


        while(pos != end){

            int xp = std::get<0>(pos);
            int yp = std::get<1>(pos);

            if(maze[yp][xp] == ' '){
                maze[yp][xp] = '*';
            }
            //std::cout << yp << " " << xp << "  " << maze[yp].size() << std::endl;
            if((xp+1 < maze[yp].size()) && (maze[yp][xp+1] == ' ')){
                std::get<0>(pos) += 1;
                maze[yp][xp+1] = '*';
                continue;

            }
            if((yp+1 < maze.size()) && (maze[yp+1][xp] == ' ')){
                std::get<1>(pos) += 1;
                maze[yp+1][xp] = '*';
                //return maze;
                continue;

            }
            if((xp-1 > 0) && (maze[yp][xp-1] == ' ')){
                std::get<0>(pos) -= 1;
                maze[yp][xp-1] = '*';
                return maze;
                continue;

            }
            if((yp-1 > 0) && (maze[yp-1][xp] == ' ')){
                std::get<1>(pos) -= 1;
                maze[yp-1][xp] = '*';
                return maze;
                continue;

            }

            
            
            else {return maze;}
        }

        return maze;

}


void lefthand(Maze &ma){

    std::tuple<int, int> start = ma.getStart();
    std::tuple<int, int> end = ma.getEnd();
    std::vector<std::vector<char>> maze = ma.getMaze();

    maze = solve(start, end, maze);

    ma.setMaze(maze);
    ma.printMaze();


}


