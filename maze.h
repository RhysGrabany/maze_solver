#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <tuple>

class Maze{

    private:
        std::vector<std::vector<char>> mzp;
        std::tuple<int, int> start, end;
    public:
        Maze();
        Maze(std::vector<std::vector<char>> mz, std::tuple<int, int> s_coords, std::tuple<int, int> e__coords);
        
        void setMaze(std::vector<std::vector<char>> mz);
        void setStart(std::tuple<int, int> s_coords);
        void setEnd(std::tuple<int, int> e_coords);

        std::vector<std::vector<char>> getMaze();



};


#endif