
#include "lefthand.h"
#include "../../classes/maze/maze.h"

#include <vector>
#include <utility>
#include <iostream>


/*
    This is a recursive method for the lefthand algorithm (keeps the wall
    to the left hand side; moving right top-down mode)
    Checks each direction before moving on and will call itself 
    until the end point is reached
    Order of precedence is: Up > Right > Down > Left
    
    in: std::pair<int,int> pos, std::pair<int,int> end, std::vector<std::vector<char>> maze
    out: std::vector<std::vector<char>> maze
*/
std::vector<std::vector<char>> solve_recurL(std::pair<int, int> pos, std::pair<int, int> end, 
    std::vector<std::vector<char>> maze){


        if(pos == end){
            return maze;
        }

        int xp = pos.first;
        int yp = pos.second;

        if(maze[yp][xp] == ' '){
            maze[yp][xp] = '*';
        } 

        if((xp+1 < maze[yp].size()) && (maze[yp][xp+1] == ' ')) {
            pos.first += 1;
            maze[yp][xp+1] = '*';
            maze = solve_recurL(pos, end, maze);
        } else if((yp+1 < maze.size()) && (maze[yp+1][xp] == ' ')) {
            pos.second += 1;
            maze[yp+1][xp] = '*';
            maze = solve_recurL(pos, end, maze);
        } else if((xp-1 > 0) && (maze[yp][xp-1] == ' ')) {
            pos.first -= 1;
            maze[yp][xp-1] = '*';
            maze = solve_recurL(pos, end, maze);
        } else if((yp-1 > 0) && (maze[yp-1][xp] == ' ')) {
            pos.second -= 1;
            maze[yp-1][xp] = '*';
            maze = solve_recurL(pos, end, maze);
        }


        return maze;

}

/*
    This is an iterative method for the lefthand algorithm (keeps the wall
    to the left hand side; moving right top-down mode)
    Checks each direction before moving on and will call itself 
    until the end point is reached
    Order of precedence is: Up > Right > Down > Left
    
    in: std::pair<int,int> pos, std::pair<int,int> end, std::vector<std::vector<char>> maze
    out: std::vector<std::vector<char>> maze
*/

std::vector<std::vector<char>> solve_iterL(std::pair<int, int> pos, std::pair<int, int> end, 
    std::vector<std::vector<char>> maze){


        while(pos != end){

            int xp = pos.first;
            int yp = pos.second;

            if(maze[yp][xp] == ' '){
                maze[yp][xp] = '*';
            } 

            if((xp+1 < maze[yp].size()) && (maze[yp][xp+1] == ' ')) {
                
                pos.first += 1;
                maze[yp][xp+1] = '*';
                continue;
            } else if((yp+1 < maze.size()) && (maze[yp+1][xp] == ' ')) {
                
                pos.second += 1;
                maze[yp+1][xp] = '*';
                continue;
            } else if((xp-1 > 0) && (maze[yp][xp-1] == ' ')) {
                
                pos.first -= 1;
                maze[yp][xp-1] = '*';
                continue;

            } else if((yp-1 > 0) && (maze[yp-1][xp] == ' ')) {
                
                pos.second -= 1;
                maze[yp-1][xp] = '*';
                continue;
            }

            return maze;
        }

        return maze;

}


void lefthand(Maze &ma){

    std::cout << "Lefthand Algorithm\n\n";

    std::pair<int, int> start = ma.getStart();
    std::pair<int, int> end = ma.getEnd();
    std::vector<std::vector<char>> maze = ma.getMaze();

    maze = solve_iterL(start, end, maze);

    if(maze[end.second][end.first] == '*'){
        ma.setSolved(true);
        std::cout << "---Maze is solved!---\n";
    } else {
        std::cout << "-Maze is not solved!-\n";
    }

    ma.setPath(maze);
    ma.printPath();


}


