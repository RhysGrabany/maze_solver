#include <iostream>

#include <vector>

/*
    in: void
    This is a small method that checks if a folder exists for output
    If the folder doesn't exist then folder is created, otherwise do nothing
*/
void makeFolder();

/*
    in: vector<vector<char>> path, string save
    This is the method responsible for outputting the vector to a txt file
    The txt file is named after the algo and whether it was solved or not
    Also saved in the folder that was created in the above method
*/
void writeTo(std::vector<std::vector<char>> maze_path, std::string save);

/*
    vector<vector<char>> path, string save
    This is the main method for this file
    Once this is called from the main method then the folder is/isn't created 
    And the file is then saved to the file's location
*/
void out(std::vector<std::vector<char>> maze_path, std::string save);