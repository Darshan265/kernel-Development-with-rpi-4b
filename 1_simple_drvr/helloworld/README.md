# Getting Started with helloworld LKM on RPI 4b

## Prerequisites (ref: https://github.com/Darshan265/MTech-Dissertation-RPI-NAS/tree/main/1.Prerequisite%20Setup )
- Raspberry Pi 4B with Raspberry Pi OS (preferably 32-bit "Buster" or later)
- build-essential, raspberrypi-kernel-headers installed
- Terminal or SSH access to Pi

## Objectives
- To check if the environment is setup properly


## Steps 
### Step 1: Set Up the Development Environment
### Step 2: Create the Module Source Files
- Create a directory named "helloworld"
- ``$mkdir ~/helloworld && cd ~/helloworld``

- Create a .c file 
- ``$ vi helloworld.c``
- Copy the content of helloworld.c in above file.

### Step 3: Write the Makefile
- Create a Makefile
- ``$vi Makefile`` 
- Copy the content of Makefile in above file.

Step 4: Compile the Kernel Module
- In the ~/helloworld  directory:
- ``$make``
- ``$ls``
- Output should include helloworld.ko.

### Step 5: Insert the Kernel Module
- ``$sudo insmod helloworld.ko``
- Verify the module is loaded:
- ``$lsmod | grep helloworld``

- View kernel log:
- ``$dmesg | tail``

You should see: 
[  903.317456] helloworld: loading out-of-tree module taints kernel.
[  903.323730] Hello world init

### Step 6: Remove the Module
``$sudo rmmod helloworld``

Check dmesg again:
``$dmesg | tail``

Expected output:
[ 1367.385378] bye bye world

### Step 7: Clean Up
- ``$make clean``



