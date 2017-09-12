mainrun.sh is the main file that runs on raspberry pi when it is switched on.
flash.py sends control signals through GPIO pins to turn the flash on.
the image is captured and renamed as samir7.jpg
flashoff.py sends control signals through GPIO pins to turn the flash off.
final.cpp performs image processing on samir7.jpg using OpenCV C++ libraries.
laserpoint.py transforms the pixel co-ordinate of image to X-Y co-ordinates of hand placed in setup
point.py sends control signals through GPIO pins to servo motors
laserpointoff.py sets the setup to its initial orientation.
