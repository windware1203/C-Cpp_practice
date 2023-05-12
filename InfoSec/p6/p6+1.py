from PIL import Image
import matplotlib.pyplot as plt

def toBin(num):
    num = bin(num)
    num = num.replace("0b","");
    num = num.zfill(3)
    return num

    
fout = open("back.txt","w")

img = Image.open("new.bmp")

width, height = img.size

SIZE = 25703 * 3
i = 0

result = ""
tmp = ""


for y in range(height):
    if i > SIZE:
            break
    for x in range(width):
        if i > SIZE:
            break   
        rgba = img.getpixel((x,y))
        tmp += str(toBIn(rgba%8))
        i += 3


for q in range(0,SIZE+1,8):
    value = 0
    for k in range(q, q+8):
        value += (int(tmp[k]) * (2 ** (7 - (k-q))))
    result += chr(value)
        
    
    

fout.write(result)
fout.close
