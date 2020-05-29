
#include "lefthand.h"
#include "../../classes/maze/maze.h"

#include <vector>
#include <tuple>
#include <iostream>


/*
    This is a recursive method for the lefthand algorithm (keeps the wall
    to the left hand side; moving right top-down mode)
    Checks each direction before moving on and will call itself 
    until the end point is reached
    Order of precedence is: Up > Right > Down > Left
    
    in: std::tuple<int,int> pos, std::tuple<int,int> end, std::vector<std::vector<char>> maze
    out: std::vector<std::vector<char>> maze
*/
std::vector<std::vector<char>> solve_recur(std::tuple<int, int> pos, std::tuple<int, int> end, 
    std::vector<std::vector<char>> maze){


        if(pos == end){
            return maze;
        }

        int xp = std::get<0>(pos);
        int yp = std::get<1>(pos);

        if(maze[yp][xp] == ' '){
            maze[yp][xp] = '*';
        } 
        if((yp-1 > 0) && (maze[yp-1][xp] == ' ')) {
            std::get<1>(pos) -= 1;
            maze[yp-1][xp] = '*';
            maze = solve_recur(pos, end, maze);

        } else if((xp+1 < maze[yp].size()) && (maze[yp][xp+1] == ' ')) {
            std::get<0>(pos) += 1;
            maze[yp][xp+1] = '*';
            maze = solve_recur(pos, end, maze);

        } else if((yp+1 < maze.size()) && (maze[yp+1][xp] == ' ')) {
            std::get<1>(pos) += 1;
            maze[yp+1][xp] = '*';
            maze = solve_recur(pos, end, maze);

        } else if((xp-1 > 0) && (maze[yp][xp-1] == ' ')) {
            std::get<0>(pos) -= 1;
            maze[yp][xp-1] = '*';
            maze = solve_recur(pos, end, maze);

        }

        return maze;

}

/*
    This is an iterative method for the lefthand algorithm (keeps the wall
    to the left hand side; moving right top-down mode)
    Checks each direction before moving on and will call itself 
    until the end point is reached
    Order of precedence is: Up > Right > Down > Left
    
    in: std::tuple<int,int> pos, std::tuple<int,int> end, std::vector<std::vector<char>> maze
    out: std::vector<std::vector<char>> maze
*/

std::vector<std::vector<char>> solve_iter(std::tuple<int, int> pos, std::tuple<int, int> end, 
    std::vector<std::vector<char>> maze){


        while(pos != end){

            int xp = std::get<0>(pos);
            int yp = std::get<1>(pos);

            if(maze[yp][xp] == ' '){
                maze[yp][xp] = '*';
            } 

            if((yp-1 > 0) && (maze[yp-1][xp] == ' ')) {
                std::get<1>(pos) -= 1;
                maze[yp-1][xp] = '*';
                continue;
            } else if((xp+1 < maze[yp].size()) && (maze[yp][xp+1] == ' ')) {
                std::get<0>(pos) += 1;
                maze[yp][xp+1] = '*';
                continue;
            } else if((yp+1 < maze.size()) && (maze[yp+1][xp] == ' ')) {
                std::get<1>(pos) += 1;
                maze[yp+1][xp] = '*';
                //return maze;
                continue;
            } else if((xp-1 > 0) && (maze[yp][xp-1] == ' ')) {
                std::get<0>(pos) -= 1;
                maze[yp][xp-1] = '*';
                continue;
            }

            return maze;
        }

        return maze;

}


void lefthand(Maze &ma){

    std::tuple<int, int> start = ma.getStart();
    std::tuple<int, int> end = ma.getEnd();
    std::vector<std::vector<char>> maze = ma.getMaze();

    int xe = std::get<0>(end);
    int ye = std::get<1>(end);

    maze = solve_recur(start, end, maze);

    if(maze[ye][xe] == '*'){
        ma.setSolved(true);
    } else {
        ma.setSolved(false);
    }

    ma.setPath(maze);
    ma.printPath();

    if(ma.getSolved()){
        std::cout << "Maze has been solved!\n";
    } else {
        std::cout << "Maze couldn't be solved!\n";
    }


}


