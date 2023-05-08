from PIL import Image
import torch
import torchvision
import torchvision.transforms as transforms
import matplotlib.pyplot as plt

img = Image.open("p3img.bmp")
width, height = img.size

# transform = transforms.Grayscale()
# img = transform(img)
xx = list()
li = list()

for i in range(256):
    xx.append(i)
    li.append(0)


size = height*width

pixel = list()
for i in range(size):
    pixel.append(0)

tmp = 0

for y in range(height):
    for x in range(width):
        rgba = img.getpixel((x,y))
        rgba += 4
        li[rgba%256] += 1
        img.putpixel((x,y), rgba)
        

    
plt.bar(xx,li)
plt.show()

img.show()
img.save("new.bmp")