#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <tuple>
#include <vector>

/*
    Class for Maze object
    this object holds the necessary info for our maze
    coords for start and end, and a 2d vector for holding the maze
*/

class Maze{

    private: // private values that must be changed through setters
        std::vector<std::vector<char>> mzp, path;
        std::tuple<int, int> start, end;        
        bool solved = false;

    public: // public methods: constructors, destructor, getters and setters
        Maze();
        Maze(std::vector<std::vector<char>> mz, std::tuple<int, int> s_coords, std::tuple<int, int> e__coords);
        Maze(std::vector<std::vector<char>> mz, std::tuple<int, int> s_coords, std::tuple<int, int> e__coords, std::vector<std::vector<char>> pa, bool so);
        ~Maze();

        void setMaze(std::vector<std::vector<char>> mz);
        void setStart(std::tuple<int, int> s_coords);
        void setEnd(std::tuple<int, int> e_coords);
        void setPath(std::vector<std::vector<char>> pa);
        void setSolved(bool s);

        std::vector<std::vector<char>> getMaze();
        std::tuple<int, int> getStart();
        std::tuple<int, int> getEnd();
        std::vector<std::vector<char>> getPath();
        bool getSolved();


        void printMaze();
        void printPath();

};

#endif