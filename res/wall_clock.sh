#!/bin/bash

DEVICE=/dev/ttyUSB0
PERIOD=1s

stty -F $DEVICE 9600 raw -echo

while true
do
        date "+%H:%M" > $DEVICE
        sleep $PERIOD
        date "+%H%M" > $DEVICE
        sleep $PERIOD
done
