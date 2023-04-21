from PIL import Image

img = Image.open("p3img.bmp")
width, height = img.size

for y in range(height):
    for x in range(width):
        rgba = img.getpixel((x,y))
        rgba >> 4;
        img.putpixel((x,y), rgba)

img.show()
img.save("new.bmp")