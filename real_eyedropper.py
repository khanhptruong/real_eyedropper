import math
from time import sleep
from PIL import Image
from picamera import PiCamera

def rgb_to_hex(rgb):
    r,g,b=rgb
    return '#%02x%02x%02x' % (r,g,b)

#constants
const_cropSize = 50

#variables
(width, height) = (0, 0)
(left, upper, right, lower) = (0, 0, 0, 0)
(red, green, blue) = (0, 0, 0)
(pixelX, pixelY) = (0, 0)
(avgR, avgG, avgB) = (0, 0, 0)
"""
camera #picamera
im #image
imCrop #image
"""

#initialize camera
camera = PiCamera()
camera.resolution = (4056, 3040)
camera.framerate = 15

#take picture
camera.start_preview(alpha=220)
sleep(5)
camera.capture('/home/pi/Pictures/Real_Eyedropper/sampler.jpg')
camera.stop_preview()

#load image
im = Image.open("/home/pi/Pictures/Real_Eyedropper/sampler.jpg")
(width, height) = im.size
print("width, height: " + repr((width, height)))

#crop center
left = (width / 2) - (const_cropSize/2)
upper = (height /2) - (const_cropSize/2)
right = (width / 2) + (const_cropSize/2)
lower = (height /2) + (const_cropSize/2)
print("left, upper, right, lower: " + repr((left, upper, right, lower)))
imCrop = im.crop((left, upper, right, lower))
#imCrop = imCrop.convert('RGB')
imCrop.save("/home/pi/Pictures/Real_Eyedropper/imCrop.jpg")

#average pixel colors together
pixel = imCrop.load()
for i in range(0, const_cropSize):
    for j in range(0, const_cropSize):
        (red, green, blue) = pixel[i, j]
        #print("ij:" + repr(i) + "," + repr(j) + " rgb:" + repr((red, green, blue)))
        avgR = avgR + (red * red)
        avgG = avgG + (green * green)
        avgB = avgB + (blue * blue)
avgR = int(math.sqrt(avgR / (const_cropSize * const_cropSize)))
avgG = int(math.sqrt(avgG / (const_cropSize * const_cropSize)))
avgB = int(math.sqrt(avgB / (const_cropSize * const_cropSize)))
print("avg RBG: " + repr((avgR, avgG, avgB)))
print(rgb_to_hex((avgR, avgG, avgB)))
print("---END PROGRAM---")