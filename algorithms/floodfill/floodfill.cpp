
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

    //std::cout << juncs << " juncs" << " "; 

    return juncs;

}

// Print the current pair 
void printPair(std::pair<int, int> p){ 
  
    std::cout << "(" << p.first << ", " << p.second << ") "; 
} 
  
// Print the Stack of Pairs 
void Showstack(std::stack<std::pair<int, int>> s){
    
    while (!s.empty()) { 
        printPair(s.top()); 
        s.pop(); 
    } 
  
    std::cout << '\n'; 
} 





std::vector<std::vector<char>> solve(std::pair<int, int> pos, std::pair<int, int> end,
    std::vector<std::vector<char>> maze){

        std::vector<std::vector<bool>> visited = vis_vec(maze);
        //std::cout << pos.second << " " << pos.first << std::endl;

        int loop = 0;

        while(pos != end){

            int juncs = junction(pos, maze, visited);

            std::stack<std::pair<int,int>> junctions;

            if(juncs > 1){
                junctions.push(std::make_pair(pos.first, pos.second));
                std::cout << junctions.top().first << " " << junctions.top().second << std::endl;
            }

            Showstack(junctions);
            std::cout << "\n";

            //if(loop == 3) {return maze;}

            //std::cout << pos.first << " " << pos.second << std::endl;

            int xp = pos.first;
            int yp = pos.second;

            if(maze[yp][xp] == ' '){
                maze[yp][xp] = '*';
            } 

            if((yp-1 > 0) && ((maze[yp-1][xp] == ' ') && (visited[yp-1][xp] == false))) {
                pos.second -= 1;
                maze[yp-1][xp] = '*';
                loop++;
                continue;

            } else if((xp+1 < maze[yp].size()) && ((maze[yp][xp+1] == ' ') && (visited[yp][xp+1] == false))) {
                pos.first += 1;
                maze[yp][xp+1] = '*';
                loop++;
                continue;

            } else if((yp+1 < maze.size()) && ((maze[yp+1][xp] == ' ') && (visited[yp+1][xp] == false))) {
                pos.second += 1;
                maze[yp+1][xp] = '*';
                loop++;
                continue;

            } else if((xp-1 > 0) &&((maze[yp][xp-1] == ' ') && (visited[yp][xp-1] == false))) {
                pos.first -= 1;
                maze[yp][xp-1] = '*';
                loop++;
                continue;
            }

            pos = std::make_pair(junctions.top().first, junctions.top().second);
            junctions.pop();

            if(junctions.empty()){
                return maze;
            }

        }

        return maze;

}


void floodfill(Maze &ma){

    std::cout << "Floodfill Algorithm\n";

    std::pair<int, int> start = ma.getStart();
    std::pair<int, int> end = ma.getEnd();
    std::vector<std::vector<char>> maze = ma.getMaze();

    //std::cout << start.second << " " << start.first << std::endl;


    maze = solve(start, end, maze);

    ma.setPath(maze);
    ma.printPath();



}