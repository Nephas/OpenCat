#/usr/bin/env bash

arduino-cli core install arduino:avr
arduino-cli compile --fqbn arduino:avr:uno OpenCat.ino
arduino-cli upload -v -p /dev/ttyUSB0 --fqbn arduino:avr:uno OpenCat.ino

