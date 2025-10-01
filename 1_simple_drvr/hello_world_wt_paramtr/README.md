
``` sudo insmod helloparam.ko name="Darshan" count=3```
```
 dmesg | tail -n 5
```
dmesg Output:
[ 1715.920908] Hello Darshan! [1/3]
[ 1715.920932] Hello Darshan! [2/3]
[ 1715.920938] Hello Darshan! [3/3]

```
rmmod helloparam.ko
```
dmesg output:
Goodbye Darshan
