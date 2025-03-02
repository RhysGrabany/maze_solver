
#include "floodfill.h"
#include "../../classes/maze/maze.h"

#include <vector>
#include <stack>
#include <utility>

int junction(std::pair<int, int> pos, std::vector<std::vector<char>> maze, std::vector<std::vector<bool>> vis){

    int xp = pos.first;
    int yp = pos.second;

    int juncs = 0;

    if((yp-1 > 0) && ((maze[yp-1][xp] == ' ') && (vis[yp-1][xp] == false))) {
        juncs+=1;
    }
    if((xp+1 < maze[yp].size()) && ((maze[yp][xp+1] == ' ') && (vis[yp][xp+1] == false))) {
        juncs+=1;
    }
    if((yp+1 < maze.size()) && ((maze[yp+1][xp] == ' ') && (vis[yp+1][xp] == false))) {
        juncs+=1;
    }
    if((xp-1 > 0) &&((maze[yp][xp-1] == ' ') && (vis[yp][xp-1] == false))) {
        juncs+=1;
    }

    return juncs;
}

std::stack<std::pair<int, int>> path_del(std::stack<std::pair<int,int>> path, 
    std::stack<std::pair<int,int>> junctions){

    while(path.top() != junctions.top()){
        path.pop();
    }

    return path;

}

std::vector<std::vector<char>> plot_maze(std::vector<std::vector<char>> maze, 
    std::stack<std::pair<int, int>> path){

        while(!path.empty()){
            int x = path.top().first;
            int y = path.top().second;

            maze[y][x] = '*';
            path.pop();
        }

        return maze;
    }



std::stack<std::pair<int,int>> solve(std::pair<int, int> pos, std::pair<int, int> end,
    std::vector<std::vector<char>> maze){

        std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));

        
        std::stack<std::pair<int,int>> path;
        std::stack<std::pair<int,int>> junctions;

        while(pos != end){
            
            int juncs = junction(pos, maze, visited);

            if(juncs > 1){
                junctions.push(std::make_pair(pos.first, pos.second));
            }

            int xp = pos.first;
            int yp = pos.second;

            if(visited[yp][xp] == false){
                visited[yp][xp] = true;
                path.push(std::make_pair(xp, yp));
            } 

            if((yp-1 > 0) && ((maze[yp-1][xp] == ' ') && (visited[yp-1][xp] == false))) {
                pos.second -= 1;
                visited[yp-1][xp] = true;
                path.push(std::make_pair(xp, yp-1));
                continue;

            } else if((xp+1 < maze[yp].size()) && ((maze[yp][xp+1] == ' ') && (visited[yp][xp+1] == false))) {
                pos.first += 1;
                visited[yp][xp+1] = true;
                path.push(std::make_pair(xp+1, yp));
                continue;

            } else if((yp+1 < maze.size()) && ((maze[yp+1][xp] == ' ') && (visited[yp+1][xp] == false))) {
                pos.second += 1;
                visited[yp+1][xp] = true;
                path.push(std::make_pair(xp, yp+1));
                continue;

            } else if((xp-1 > 0) &&((maze[yp][xp-1] == ' ') && (visited[yp][xp-1] == false))) {
                pos.first -= 1;
                visited[yp][xp-1] = true;
                path.push(std::make_pair(xp-1, yp));
                continue;
            }

            if(junctions.empty()){
                return path;
            } else {

                pos = junctions.top();
                path = path_del(path, junctions);
                junctions.pop();
            }
        }
        return path;
}


void floodfill(Maze *ma){

    std::cout << "Floodfill Algorithm\n\n";

    std::pair<int, int> start = ma->getStart();
    std::pair<int, int> end = ma->getEnd();
    std::vector<std::vector<char>> maze = ma->getMaze();

    std::stack<std::pair<int,int>> path;

    path = solve(start, end, maze);
    maze = plot_maze(maze, path);

    ma->setPath(maze);
    ma->printPath();

    if(path.top() == end){
        ma->setSolved(true);
        std::cout << "---Maze is solved!---\n";
    } else {
        std::cout << "-Maze is not solved!-\n";
    }

}