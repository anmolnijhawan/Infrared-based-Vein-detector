import RPi.GPIO as GPIO
import time


GPIO.setmode(GPIO.BOARD)
GPIO.setup(12,GPIO.OUT)

GPIO.output(12,GPIO.HIGH)
time.sleep(4)
GPIO.cleanup()

