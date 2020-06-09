#!/usr/bin/python3
from PIL import Image, ImageOps

class Maze:

    def __init__(self, text=None, image=None):
        self.m_Text = text
        self.m_Image = image
    
    def setText(self, text):
        self.m_Text = text
    def setImage(self, image):
        self.m_Image = image

    def getText(self):
        return self.m_Text
    def getImage(self):
        return self.m_Image

    def printText(self):
        for i in self.m_Text:
            print("".join(i))
    def saveImage(self):
        self.m_Image.save("outImage.png")

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


    rotated = im.transpose(Image.ROTATE_270)
    flip = ImageOps.mirror(rotated)

    maze.setImage(flip)


def parseText(maze):

    txt = open("outputs/output.txt")

    mz = []

    for line in txt.readlines():
        li = []
        for i in line.strip():
            li.append(i)
        mz.append(li)

    maze.setText(mz)

def main():

    maze = Maze()

    parseText(maze)
    createImage(maze)
    maze.saveImage()



if __name__ == "__main__":
    main()