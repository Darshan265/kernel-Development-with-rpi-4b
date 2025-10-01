# kernel-Development-with-rpi-4b
-Projects related to kernel development with raspberry pi 4B( ARM Cortex A-72). 

## Prerequisites
- Raspberry Pi 4B with Raspberry Pi OS (preferably 32-bit "Buster" or later)
- build-essential, raspberrypi-kernel-headers installed
- Terminal or SSH access to Pi

## Set UP the Development Environment
On Rapsberry Pi 4B, run:
- ``$sudo apt update``
- ``$sudo apt install build-essential raspberrypi-kernel-headers -y``

Verify header location (typically /lib/modules/$(uname -r)/build exists):
- ``$ls /lib/modules/$(uname -r)/build``






