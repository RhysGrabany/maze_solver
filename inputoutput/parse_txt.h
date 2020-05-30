#ifndef PARSE_TXT_H
#define PARSE_TXT_H

#include "../classes/maze/maze.h"

template<class T>
void print_vector(std::vector<std::vector<T>> const ma);

template <class T>
std::vector<std::vector<T>> maze_parse(std::istream& stream, std::vector<std::vector<T>> maze);

std::pair<int, int> coords_parse(std::string unprse);

void parse(std::istream& stream, Maze& maze);

#endif