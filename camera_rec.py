import os
from os import listdir
from os.path import isfile, join

import random
import time
import serial

import numpy as np
from numpy import expand_dims
from keras.models import load_model
from keras.utils import CustomObjectScope
from keras.initializers import glorot_uniform
from keras.preprocessing.image import load_img
from keras import backend as K

from keras.preprocessing.image import img_to_array
from matplotlib import pyplot
from matplotlib.patches import Rectangle

from sklearn.metrics import confusion_matrix
import picamera

port = '/dev/ttyACM0'
baudrate = 9600
ser = serial.Serial(port, baudrate)

K.clear_session()

# takes dilename and target size and returns scaled pixel data for the keras model
def load_image_pixels(filename, shape):
    # load the image to get its shape
    image = load_img(filename)
    width, height = image.size
    # load the image with the required size
    image = load_img(filename, target_size=shape)
    # convert to numpy array
    image = img_to_array(image)
    # scale pixel values to [0, 1]
    image = image.astype('float32')
    image /= 255.0
    # add a dimension so that we have one sample
    image = expand_dims(image, 0)
    return image, width, height

labels = ['cardboard/paper','glass/metal/plastic','glass/metal/plastic','cardboard/paper','glass/metal/plastic','trash']
output = {'cardboard/paper':0, 'glass/metal/plastic':8, 'trash':9}
accuracy = [0,0,0,0,0,0]
count = -1
right = 0
label = []
prediction = []

# with CustomObjectScope({'GlorotUniform': glorot_uniform()}):
model = load_model('garbage.h5')
input_w, input_h = 224, 224

#camera = picamera.PiCamera()

while (True):
    photo_filename = '/home/pi/class/YOLO/img.jpeg'
    
    camera.start_preview()
    
    time.sleep(5)
    camera.capture(photo_filename)
    camera.stop_preview()
    
    image, image_w, image_h = load_image_pixels(photo_filename, (input_w, input_h))
    os.remove(photo_filename)
    yhat = model.predict(image)
    maximum = np.argmax(yhat)
    
    # activate arduino
    print(labels[maximum])
    signal = str(output[labels[maximum]])
    ser.write( chr(signal).encode() )
    print('Sent', signal)

    K.clear_session()