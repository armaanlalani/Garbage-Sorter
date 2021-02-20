The `servo-setup.ino` code is the code programmed onto the Arduino Mega 2560.
The Arduino Mega acts as a receiver for serial bytes transmitted by the Raspberry Pi.
When receiving a certain byte, this triggers the Arduino to control the standard rotation servo motor rotation to a specified angle.

The `pusher.ino` code is an older Arduino code that is meant to control continuous rotation servo motors. 
