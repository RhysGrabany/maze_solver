
classes = classes/maze/maze.cpp
algorithms = algorithms/lefthand/lefthand.cpp algorithms/righthand/righthand.cpp algorithms/floodfill/floodfill.cpp

all:
	g++ -o main main.cpp inputoutput/parse_txt.cpp $(classes) $(algorithms)


