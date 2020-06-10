#include "output.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

void makeFolder(){

    std::string folder = "outputs";

    if(!fs::is_directory(folder)){
        fs::create_directory(folder);
    }

}

void writeTo(std::vector<std::vector<char>> maze_path, std::string save){

    std::ofstream outfile;
    outfile.open("outputs/" + save);


    for(int i = 0; i < maze_path.size(); i++){
        for(int j = 0; j < maze_path[i].size(); j++){
            outfile << maze_path[i][j];
        }
        outfile << "\n";
    }

    outfile.close();

}

void out(std::vector<std::vector<char>> maze_path, std::string save){

    makeFolder();
    writeTo(maze_path, save);


}