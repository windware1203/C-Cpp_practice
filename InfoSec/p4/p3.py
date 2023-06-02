from PIL import Image
import torch
import torchvision.transforms as transforms
import matplotlib.pyplot as plt #長條圖

img = Image.open("p3img.bmp") #開圖片
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

#跑整張圖片
for y in range(height):
    for x in range(width):
        rgba = img.getpixel((x,y)) #取得每個像素的值
        li[rgba%256] += 1 #將那個rgba+1
        img.putpixel((x,y), rgba)
        

for i in range(256):
    print(str(xx[i]) + ':' + str(li[i]) )
 
#plt.bar(xx,li) #長條圖
#plt.show()

img.show()
img.save("new.bmp")