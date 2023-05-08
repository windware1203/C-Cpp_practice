from PIL import Image
import matplotlib.pyplot as plt


def toBin(num):
    num = bin(num)
    num = num.replace("0b","");
    num = num.zfill(8)
    return num

fin = open("text.txt")
str = ""
binn = ""
for i in fin:
    str+=i
for i in range(len(str)):
    binn += toBin(ord(str[i]))
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
        s = bytearray(toBin(rgba),'utf-8')
        if binn[i] == 1 :
            s[7] = 1
        else:
            s[7] = 0
        i += 1

        img.putpixel((x,y), int(s.decode('utf-8')))

img.save("new.bmp")
fin.close