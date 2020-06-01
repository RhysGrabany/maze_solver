
#include "floodfill.h"
#include "../../classes/maze/maze.h"

#include <vector>
#include <utility>

std::vector<std::vector<std::pair<char, bool>>> vis_vec(std::vector<std::vector<char>> maze){

    std::vector<std::vector<std::pair<char, bool>>> visited;

    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){
            if(maze[i][j] == '#'){
                visited[i][j] = std::make_pair('#', false);
            } else {
                visited[i][j] = std::make_pair(' ', false);
            }
        }
    }

    return visited;



}


std::vector<std::vector<char>> solve(std::pair<int, int> pos, std::pair<int, int> end,
    std::vector<std::vector<char>> maze){
    
    std::vector<std::vector<std::pair<char, bool>>> visited = vis_vec(maze);




}


void floodfill(Maze &ma){

    std::pair<int, int> start = ma.getStart();
    std::pair<int, int> end = ma.getEnd();
    std::vector<std::vector<char>> maze = ma.getMaze();

    maze = solve(start, end, maze);






}