# attiny2313_clock
Simple clock using attiny2313 and 7 segment indicator
=======================================================

Hardware details:
* 1x  ATTtiny2313
* 1x  3686400Hz quartz
* 2x  20p ceramic capcitor
* 1x  0.1uF ceramic capcitor
* 1x  47uF capacitor(5x5.3)
* 1x  DIP 20 socket
* 10x 510ohm resistor
* 1x  led
* 1x  30k resistor
* 1x  FYQ-3641AS led display

You also need UART->USB converter.
To show time run watch "date +%H:%M > /dev/ttyUSB0"

<img src="/img/cheme.png" width="350"/>
<img src="/img/photo.png" width="350"/>
