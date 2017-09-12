#!/bin/bash
#mainrun.sh
cd  /home/pi

python flash.py
raspistill -o samir7.jpg
python flashoff.py
g++ final.cpp -o final `pkg-config --cflags --libs opencv`
./final
python laserpoint.py
python point.py
python laserpointoff.py