
#include "righthand.h"
#include "../../classes/maze/maze.h"

#include <vector>
#include <utility>
#include <iostream>


/*
    This is a recursive method for the righthand algorithm (keeps the wall
    to the right hand side; moving left top-down mode)
    Checks each direction before moving on and will call itself 
    until the end point is reached
    Order of precedence is: Up > Left > Down > Right
    
    in: std::pair<int,int> pos, std::pair<int,int> end, std::vector<std::vector<char>> maze
    out: std::vector<std::vector<char>> maze
*/
std::vector<std::vector<char>> solve_recurR(std::pair<int, int> pos, std::pair<int, int> end, 
    std::vector<std::vector<char>> maze){


        if(pos == end){
            return maze;
        }

        int xp = pos.first;
        int yp = pos.second;

        if(maze[yp][xp] == ' '){
            maze[yp][xp] = '*';
        } 

        if((xp-1 > 0) && (maze[yp][xp-1] == ' ')) {
            pos.first -= 1;
            maze[yp][xp-1] = '*';
            maze = solve_recurR(pos, end, maze);

        } else if((yp+1 < maze.size()) && (maze[yp+1][xp] == ' ')) {
            pos.second += 1;
            maze[yp+1][xp] = '*';
            maze = solve_recurR(pos, end, maze);
        
        } else if((yp-1 > 0) && (maze[yp-1][xp] == ' ')) {
            pos.second -= 1;
            maze[yp-1][xp] = '*';
            maze = solve_recurR(pos, end, maze);
        
        } else if((xp+1 < maze[yp].size()) && (maze[yp][xp+1] == ' ')) {
            pos.first += 1;
            maze[yp][xp+1] = '*';
            maze = solve_recurR(pos, end, maze);
        }


        return maze;

}

/*
    This is an iterative method for the righthand algorithm (keeps the wall
    to the right hand side; moving left top-down mode)
    Checks each direction before moving on and will call itself 
    until the end point is reached
    Order of precedence is: Down > Left > Up > Right
    
    in: std::pair<int,int> pos, std::pair<int,int> end, std::vector<std::vector<char>> maze
    out: std::vector<std::vector<char>> maze
*/

std::vector<std::vector<char>> solve_iterR(std::pair<int, int> pos, std::pair<int, int> end, 
    std::vector<std::vector<char>> maze){


        while(pos != end){

            int xp = pos.first;
            int yp = pos.first;

            if(maze[yp][xp] == ' '){
                maze[yp][xp] = '*';
            } 
            
            if((xp-1 > 0) && (maze[yp][xp-1] == ' ')) {
                pos.first -= 1;
                maze[yp][xp-1] = '*';
                continue;

            } else if((yp+1 < maze.size()) && (maze[yp+1][xp] == ' ')) {
                pos.second += 1;
                maze[yp+1][xp] = '*';
                continue;

            } else if((yp-1 > 0) && (maze[yp-1][xp] == ' ')) {
                pos.second -= 1;
                maze[yp-1][xp] = '*';
                continue;
            
            } else if((xp+1 < maze[yp].size()) && (maze[yp][xp+1] == ' ')) {
                pos.first += 1;
                maze[yp][xp+1] = '*';
                continue;
            }

            return maze;
        }

        return maze;

}


void righthand(Maze *ma){

    std::cout << "Righthand Algorithm\n\n";

    std::pair<int, int> start = ma->getStart();
    std::pair<int, int> end = ma->getEnd();
    std::vector<std::vector<char>> maze = ma->getMaze();

    maze = solve_recurR(start, end, maze);

    if(maze[end.second][end.first] == '*'){
        ma->setSolved(true);
        std::cout << "---Maze is solved!---\n";
    } else {
        std::cout << "-Maze is not solved!-\n";
    }

    ma->setPath(maze);
    ma->printPath();

}


