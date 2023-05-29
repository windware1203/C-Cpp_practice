from PIL import Image
import matplotlib.pyplot as plt


def toBin(num):
    num = bin(num)
    num = num.replace("0b","");
    num = num.zfill(8)
    return num

fin = open("text.txt")
strr = ""
binn = ""
for i in fin:
    strr+=i
for i in range(len(strr)):
    binn += toBin(ord(strr[i]))
    
img = Image.open("img.bmp")
width, height = img.size


#for y in range(height):
#    for x in range(width):
#        rgba = img.getpixel((x,y))
#        img.putpixel((x,y), rgba)
i = 0

for y in range(height):
    if(i >= len(binn)):
        break
    for x in range(width):
        if(i >= len(binn)):
            break
        rgba = img.getpixel((x,y))
         
        threeBit = rgba % 8
        rgba -= threeBit

        if binn[i] == '1':
            rgba += 4
        i += 1
         
        if binn[i] == '1':
            rgba += 2
        i += 1

        if binn[i] == '1':
             rgba += 1
        
        #if (rgba % 2) == 0:
        #    if binn[i] == '1':
        #        rgba += 1
        #else:
        #    if binn[i] == '0':
        #        rgba -= 1
        img.putpixel((x,y), rgba)
        i += 1
        
print(i)
img.save("new.bmp")
fin.close
