#!/usr/bin/python3
from PIL import Image, ImageOps
import argparse


parser = argparse.ArgumentParser()
parser.add_argument("-i", "--input")
parser.add_argument("-o", "--output")

"""
    Maze class
    Holds the text and image relating to a maze
"""
class Maze:

    ###############
    # Constructor #
    ###############
    def __init__(self, text=None, image=None):
        self.m_Text = text
        self.m_Image = image

    ###########
    # Setters #
    ###########
    def setText(self, text):
        self.m_Text = text
    def setImage(self, image):
        self.m_Image = image
    def setWidth(self, width):
        self.m_Width = width
    def setHeight(self, height):
        self.m_Height = height
    def setPathColour(self, colour):
        self.m_PathColour = colour
    
    ###########
    # Getters #
    ###########
    def getText(self):
        return self.m_Text
    def getImage(self):
        return self.m_Image
    def getWidth(self):
        return self.m_Width
    def getHeight(self):
        return self.m_Height
    def getPathColour(self):
        return self.m_PathColour

    ###########
    # Methods #
    ###########

    #Mostly a debugging tool to show the text from parsing text file
    def printText(self):
        for i in self.m_Text:
            print("".join(i))
    #Method used to save the image to file
    def saveImage(self, outname):
        self.m_Image.save("outputs/images/" + outname + ".png")
    #Method used to save text to file
    def saveText(self, outname):
        saving = self.getText()
        
        height = self.getHeight()
        width = self.getWidth()

        out = "outputs/text/" + outname + ".txt"

        with open(out, 'w') as f:
            f.write(str(width) + "\n" + str(height) + "\n")
            for ele in saving:
                for i in ele:
                    f.write(i)
                f.write("\n")

"""
    This method aims to create an image using a textfile input
    This can work if there is no path or if there is a path
"""
def createImage(maze):
    txt = maze.getText()

    im = Image.new("RGB", (len(txt), len(txt[0])), "#000000")
    pixels = im.load()

    for i in range(0,len(txt)):
        for j in range(0 ,len(txt[i])):
            if txt[i][j] == "#":
                pass
            elif txt[i][j] == " ":
                pixels[i, j] = (255, 255, 255)
            elif txt[i][j] == "*":
                pixels[i, j] = maze.getPathColour()

    # For some reason, done normally the image is flipped and rotated, this makes it rightside up
    rotated = im.transpose(Image.ROTATE_270)
    flip = ImageOps.mirror(rotated)

    maze.setImage(flip)

"""
    This method aims to parse text from a textfile and store it into the maze object
"""
def parseText(maze, loc):

    txt = open(loc)

    mz = []
    for line in txt.readlines():
        li = []
        for i in line.strip():
            li.append(i)
        mz.append(li)

    maze.setText(mz)


def parseImage(maze, loc):

    im = Image.open(loc)

    rotated = im.transpose(Image.ROTATE_270)
    flip = ImageOps.mirror(rotated)

    txt = []

    pix = flip.load()
    height, width = flip.size

    for x in range(0, height):
        line = []
        for y in range(0, width):
            if pix[x, y] >= (0, 0, 0) and pix[x,y] <= (20,20,20):
                line.append("#")
            elif pix[x, y] >= (230, 230, 230) and pix[x,y] <= (255, 255, 255):
                line.append(" ")
            elif pix[x, y] == (49, 201, 1):
                line.append("*")
        txt.append(line)


    maze.setHeight(height)
    maze.setWidth(width)

    maze.setText(txt)


def main():

    maze = Maze()

    parsed = parser.parse_args()

    inp = parsed.input
    outp = parsed.output

    greenpath = (49, 201, 1)
    redpath = (255, 0, 0)
    path = redpath if ("NotSolved" in inp) else greenpath
    maze.setPathColour(path)

    if(".txt" in parsed.input):
        parseText(maze, inp)
        createImage(maze)
        maze.saveImage(outp)
    else:
        parseImage(maze, inp)
        maze.saveText(outp)


if __name__ == "__main__":
    main()