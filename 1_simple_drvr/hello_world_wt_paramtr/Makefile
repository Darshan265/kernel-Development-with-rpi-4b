obj-m += helloparam.o
# Tells the kernel build system to build helloparam.c as a loadable module (helloparam.ko)

KDIR := /lib/modules/$(shell uname -r)/build
# Sets KDIR to the path of the current kernel's build directory (where headers/Makefiles are located)

PWD := $(shell pwd)
# Sets PWD to the current working directory — where your module source (helloparam.c) is

all:
	make -C $(KDIR) M=$(PWD) modules
# 'all' is the default make target.
# -C tells make to switch to the kernel build directory (KDIR)
# M=$(PWD) tells the kernel to build the module in your current directory

clean:
	make -C $(KDIR) M=$(PWD) clean
# 'clean' target — removes all generated files (like .ko, .o, .mod.c, .symvers)
