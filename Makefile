
classes = classes/maze/maze.cpp classes/graph/graph.cpp classes/graph/node.cpp
algorithms = algorithms/lefthand/lefthand.cpp algorithms/righthand/righthand.cpp algorithms/floodfill/floodfill.cpp algorithms/depthfirst/depthfirst.cpp
io = inputoutput/parse_txt.cpp inputoutput/output.cpp

all:
	g++ -o main main.cpp $(io) $(classes) $(algorithms) -lstdc++fs


