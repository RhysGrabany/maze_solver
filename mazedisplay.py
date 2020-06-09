#!/usr/bin/python3
from PIL import Image, ImageOps

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
    
    ###########
    # Getters #
    ###########
    def getText(self):
        return self.m_Text
    def getImage(self):
        return self.m_Image

    ###########
    # Methods #
    ###########

    #Mostly a debugging tool to show the text from parsing text file
    def printText(self):
        for i in self.m_Text:
            print("".join(i))
    #Method used to save the image to file
    def saveImage(self):
        self.m_Image.save("outImage.png")

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
                pixels[i, j] = (49, 201, 1)

    # For some reason, done normally the image is flipped and rotated, this makes it rightside up
    rotated = im.transpose(Image.ROTATE_270)
    flip = ImageOps.mirror(rotated)

    maze.setImage(flip)

"""
    This method aims to parse text from a textfile and store it into the maze object
"""
def parseText(maze):

    txt = open("outputs/output.txt")

    mz = []
    for line in txt.readlines():
        li = []
        for i in line.strip():
            li.append(i)
        mz.append(li)

    maze.setText(mz)


def parseImage(maze):

    im = Image.open("outImage.png")

    rotated = im.transpose(Image.ROTATE_270)
    flip = ImageOps.mirror(rotated)

    txt = []

    pix = flip.load()
    width, height = flip.size
    print(width, height)
    for x in range(0, width):
        line = []
        for y in range(0, height):
            print(x, y)
            if pix[x, y] == (0, 0, 0):
                line.append("#")
            elif pix[x, y] == (255, 255, 255):
                line.append(" ")
            elif pix[x, y] == (49, 201, 1):
                line.append("*")
        txt.append(line)
    
    maze.setText(txt)




def main():

    maze = Maze()

    parseImage(maze)
    maze.printText()
    #parseText(maze)
    #createImage(maze)
    #maze.saveImage()


if __name__ == "__main__":
    main()