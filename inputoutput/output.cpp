#include "output.h"

#include <vector>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;



void makeFolder(){

    std::string folder = "outputs";


    if(!fs::is_directory(folder)){
        fs::create_directory(folder);
    }


}

void writeTo(){

    

}

void out(std::vector<std::vector<char>> mazePath){

    makeFolder();


}