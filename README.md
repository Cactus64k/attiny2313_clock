Simple clock using ATTiny2313 and 7 segment indicator
=======================================================

Hardware details:<br/>
* 1x  ATTtiny2313
* 1x  3686400Hz quartz
* 2x  20p ceramic capcitor
* 1x  0.1uF ceramic capcitor
* 1x  47uF capacitor(5x5.3)
* 1x  DIP 20 socket
* 1x  0ohm resistor
* 10x 510ohm resistor
* 1x  led
* 1x  30k resistor
* 1x  FYQ-3641AS led display

You also need UART->USB converter or MAX3232.<br/>
Baud rate is 9600<br/>
You need pick files to folders:<br/>
/opt/wall_clock.sh<br/>
/etc/systemd/system/wall_clock.service<br/>

Also you can use LED_ON or LED_OFF command like<br/>
echo "LED_ON" > /dev/ttyUSB0<br/>


<img src="/img/cheme.png" width="350"/>
<img src="/img/photo.png" width="350"/>
