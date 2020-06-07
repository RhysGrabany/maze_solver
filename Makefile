
classes = classes/maze/maze.cpp
algorithms = algorithms/lefthand/lefthand.cpp algorithms/righthand/righthand.cpp algorithms/floodfill/floodfill.cpp
io = inputoutput/parse_txt.cpp inputoutput/output.cpp

all:
	g++ -o main main.cpp $(io) $(classes) $(algorithms) -lstdc++fs


