
#include "floodfill.h"
#include "../../classes/maze/maze.h"

#include <vector>
#include <stack>
#include <utility>

std::vector<std::vector<bool>> vis_vec(std::vector<std::vector<char>> maze){

    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), 0));

    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){
            visited[i][j] = false;
        }
    }

    return visited;

}

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

// Print the current pair 
void printPair(std::pair<int, int> p){ 
  
    std::cout << "(" << p.first << ", " << p.second << ") "; 
} 
  
// Print the Stack of Pairs 
void showstack(std::stack<std::pair<int, int>> s){
    
    while (!s.empty()) { 
        printPair(s.top()); 
        s.pop(); 
    } 
  
    std::cout << '\n'; 
} 


std::stack<std::pair<int, int>> path_del(std::stack<std::pair<int,int>> path, 
    std::stack<std::pair<int,int>> junctions){

    std::cout << "Deleting path\n";
    while(path.top() != junctions.top()){
        path.pop();
    }

    return path;

}

std::vector<std::vector<char>> plot_maze(std::vector<std::vector<char>> maze, 
    std::stack<std::pair<int, int>> path){
        
    }



std::stack<std::pair<int,int>> solve(std::pair<int, int> pos, std::pair<int, int> end,
    std::vector<std::vector<char>> maze){

        std::vector<std::vector<bool>> visited = vis_vec(maze);
        
        std::stack<std::pair<int,int>> path;
        std::stack<std::pair<int,int>> junctions;

        int loop = 0;

        while(pos != end){
            printf("Curr Coords: (%i, %i)\n", pos.first, pos.second);
            //std::cout << "Curr Coords: (" << pos.first << ", " << pos.second << ")" << std::endl;

            int juncs = junction(pos, maze, visited);

            if(juncs > 1){
                junctions.push(std::make_pair(pos.first, pos.second));
                //std::cout << "Juncs: " << juncs << " Coords: " << junctions.top().first << " " << junctions.top().second << std::endl;
            }

            int xp = pos.first;
            int yp = pos.second;

            if(visited[yp][xp] == false){
                visited[yp][xp] = true;
                path.push(std::make_pair(yp, xp));
            } 

            if((yp-1 > 0) && ((maze[yp-1][xp] == ' ') && (visited[yp-1][xp] == false))) {
                pos.second -= 1;
                visited[yp-1][xp] = true;
                path.push(std::make_pair(xp, yp-1));
                loop++;
                continue;

            } else if((xp+1 < maze[yp].size()) && ((maze[yp][xp+1] == ' ') && (visited[yp][xp+1] == false))) {
                pos.first += 1;
                visited[yp][xp+1] = true;
                path.push(std::make_pair(xp+1, yp));
                loop++;
                continue;

            } else if((yp+1 < maze.size()) && ((maze[yp+1][xp] == ' ') && (visited[yp+1][xp] == false))) {
                pos.second += 1;
                visited[yp+1][xp] = true;
                path.push(std::make_pair(xp, yp+1));
                loop++;
                continue;

            } else if((xp-1 > 0) &&((maze[yp][xp-1] == ' ') && (visited[yp][xp-1] == false))) {
                pos.first -= 1;
                visited[yp][xp-1] = true;
                path.push(std::make_pair(xp-1, yp));
                loop++;
                continue;
            } else {

                if(junctions.empty()){
                    return path;
                
                } else {
                    pos = junctions.top();
                    junctions.pop();
                    path = path_del(path, junctions);
                }

            }

            loop++;

        }

        return path;

}


void floodfill(Maze &ma){

    std::cout << "Floodfill Algorithm\n";

    std::pair<int, int> start = ma.getStart();
    std::pair<int, int> end = ma.getEnd();
    std::vector<std::vector<char>> maze = ma.getMaze();

    //std::cout << start.second << " " << start.first << std::endl;

    std::stack<std::pair<int,int>> path;


    path = solve(start, end, maze);

    //showstack(path);

    std::cout << std::endl;
    ma.printMaze();


    //ma.setPath(maze);
    //ma.printPath();



}