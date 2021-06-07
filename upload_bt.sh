#/usr/bin/env bash

sudo rfcomm bind rfcomm0 77:90:17:87:71:26
arduino-cli core install arduino:avr
arduino-cli compile --fqbn arduino:avr:uno OpenCat.ino
arduino-cli upload -v -p /dev/rfcomm0 --fqbn arduino:avr:uno OpenCat.ino

