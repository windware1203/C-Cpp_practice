from PIL import Image
import matplotlib.pyplot as plt


    
fout = open("back.txt","w")

img = Image.open("new.bmp")
img2 = Image.open("img.bmp")
width, height = img.size


size = height*width

i = 0
str = ""
for y in range(height):
    for x in range(width):
        rgba = img.getpixel((x,y))
        rgba2 = img2.getpixel((x,y))


fout.write(str)
fout.close