# Maze Solving 
## Features
#### C++ File
- Take in a properly formatted txt file
- Use different algorithms to attempt to solve mazes
    - Lefthand Algorithm
    - Righthand Algorithm
    - Floodfill Algorithm
- Output a txt file the path used to solve the maze 
#### Python File
- Take in a txt or image file
    - Text file will then be parsed and turned into an image file
    - Image file is parsed and then turned into a properly formatted text file that can be used by the Cpp file
- Text file that contains a solved maze (evident by the filename being "Solved"), the path will be green, otherwise the path will be red


## Algorithms
#### Lefthand Algorithm
This algorithm is pretty easy to understand. The algo will move through the maze and will keep the wall on it's left side; looking at it from above it will look like it is going right. The algo will keep to this rule until it meets a deadend and then it will stop and return the maze with path.

#### Righthand Algorithm
This algorithm is quite like the Lefthand algorithm however instead of keeping the wall on the left, this time it will keep the wall on the right on try to move through the maze that way. And again, once the algo hits a deadend it will return the path.

#### Floodfill Algorithm
This algorithm is different from the last two. The algo will work through the maze like normal, however when it meets a part of the maze where there is more than one possible route (such as a junction) then it will save the coord into a stack. The algo also saves the coords of the path into a different stack so it doesn't have to modify the original maze. It will keep doing this for every junction it meets until it reaches a deadend. From there it will pop the first element of the junctions stack and then remove all the coords in the path stack until that last junction coord. This repeats until the first solution is found and returns the maze along with it's path.

## Rules
As such with most programs, this one has a few rules that I followed and must be followed in order to use it properly:

1. The paths and walls to a maze must be 1px*1px in size

This is a simple explanation as to why: Each pixel in the maze is parsed from the image into a text counterpart where each black pixel will make a single '#' for the wall, or each white pixel will make a single ' ' (blank space). This is due to how the cpp file parses the text in order for it to be used by the algorithms.

2. There must be a wall on the entire outside of the maze, with one white space on the top and bottom for start and end points

This is to make it a little easier to parse the coordinates of the maze's start and end points without having external help from the user. Having it this way will take some effort off the user in my opinion.

3. The maze text file must have the width and height of the maze (in that order, one per line) before the actual maze

This is just to make it sort of easier to allocate space for the 2d vector that holds the parsed maze. This way it can be static and won't dynamically allocate the memory when needed.

---

[This is a good website to generate mazes with these rules.](https://hereandabove.com/maze/mazeorig.form.html) However they also come with a white border that will need to be cropped out. This is a good resource to use until my own is developed. And the files are saved as gif and will need to be converted to jpg before my python file is able to parse it into text.

---
### Footnote

This was my first program in C++ coming from a pure Python background and as such, some of the choices I make regarding program structure and technologies used can probably be questionable if seen by a more experienced C++ programmer.

Hopefully I can use this program as a learning experience in the future, but I enjoyed working with the language and I look forward to what I can try to make in the future.