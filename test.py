# load yolov3 model and perform object detection
# based on https://github.com/experiencor/keras-yolo3

import numpy as np
from numpy import expand_dims
from keras.models import load_model
from keras.utils import CustomObjectScope
from keras.initializers import glorot_uniform
from keras.preprocessing.image import load_img
from keras.preprocessing.image import img_to_array
from matplotlib import pyplot
from matplotlib.patches import Rectangle


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

labels = ['cardboard','glass','metal','paper','plastic','trash']

# load yolov3 model
with CustomObjectScope({'GlorotUniform': glorot_uniform()}):
        model = load_model('garbage.h5')
# define the expected input shape for the model
input_w, input_h = 224, 224
# define our new photo
photo_filename = './bottle1.png' # PUT IN THE FILENAME HERE
# load and prepare image
image, image_w, image_h = load_image_pixels(photo_filename, (input_w, input_h))
# make prediction
yhat = model.predict(image)
maximum = np.argmax(yhat)
print("Prediction is: " + labels[maximum])