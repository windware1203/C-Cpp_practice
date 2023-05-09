from PIL import Image
import matplotlib.pyplot as plt


    
fout = open("back.txt","w")

img = Image.open("new.bmp")

width, height = img.size

SIZE = 25703
i = 0

result = ""
tmp = ""


for y in range(height):
    if i > 25703:
            break
    for x in range(width):
        if i > 25703:
            break   
        rgba = img.getpixel((x,y))
        tmp += str(rgba%2)
        i += 1


for q in range(0,25704,8):
    value = 0
    for k in range(q, q+8):
        value += (int(tmp[k]) * (2 ** (7 - (k-q))))
    result += chr(value)
        
    
    

fout.write(result)
fout.close