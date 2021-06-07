#/usr/bin/env bash

sudo rfcomm release rfcomm0
sudo rfcomm bind rfcomm0 77:90:17:87:71:26
arduino-cli core install arduino:avr
arduino-cli compile --fqbn arduino:avr:uno Main.ino
arduino-cli upload -v -p /dev/rfcomm0 --fqbn arduino:avr:uno Main.ino

