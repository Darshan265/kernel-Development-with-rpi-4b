#tell kernel to build helloworld.o as a loadable module
obj-m += helloworld.o

# KDIR points to the kernel build directory for the currently running kernel
KDIR := /lib/modules/$(shell uname -r)/build

# PWD stores the present working directory where your module source is
PWD  := $(shell pwd)

# 'all' is the default target. It tells make to invoke the kernel's build system
# with 'modules' target from your module directory
all:
        # -C changes to the kernel build directory
        # M=$(PWD) tells the kernel to look in your current directory for the module source
        make -C $(KDIR) M=$(PWD) modules

# 'clean' is a custom rule to clean up the module build files
clean:
        # It tells the kernel build system to clean the files from your module directory
        make -C $(KDIR) M=$(PWD) clean

