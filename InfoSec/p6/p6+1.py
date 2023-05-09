from PIL import Image
import matplotlib.pyplot as plt


    
fout = open("back.txt","w")

img = Image.open("new.bmp")

width, height = img.size

SIZE = 25703
i = 0

result = ""
tmp = 0
j = 7

for y in range(height):
    if i > 25703:
            break
    for x in range(width):
        if i > 25703:
            break
        if j < 0:
            result += chr(tmp)
        rgba = img.getpixel((x,y))
        if rgba % 2 == 0:
             continue
        else:
            tmp += int((rgba % 2) ** j)
        i += 1
        j -= 1




fout.write(result)
fout.close