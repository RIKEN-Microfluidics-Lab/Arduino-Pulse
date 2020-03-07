# Arduino-Pulse
pulse generator to trigger multiple devices serially.

### How this works
read a serial command a 0/1 train specifying off/on of five channels.
serial command is like "m01011"


### The pin layout of arduino
The digital pins of 2-6 are for output ttl signals for individual devices.
The pin number of 11 is the syncin (TTL in to generate high/low source).







