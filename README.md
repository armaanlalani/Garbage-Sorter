# Garbage-Sorter
This repository contains the image recognition model and arduino code to implement the garbage sorting solution for the MakeUofT hackathon.

To see some 
'test.py' includes code you can run to test out the image classification model for garbage categories.
Our rasberry pi device contains the python file camera_rec.py and pretrained weights for VGG16 to perform image classification on garbage. It also includes code to 
run the pi camera module v2 so that it can take photos and pass it through the classification model. 

As such, running 'python camera_rec.py' on the raspberry pi with the camera module enabled will load the model weights and pass signals to the arduino which allows
us to sort garbage automatically. 
