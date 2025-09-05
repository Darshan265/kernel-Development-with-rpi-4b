// Includes the core header for loadable kernel modules.
// Automatically pulls in other useful headers like linux/init.h and linux/kernel.h
#include<linux/module.h>

// This is the initialization function. It runs when the module is loaded with insmod.
// __init is a macro that tells the kernel this function is only used during initialization.
// pr_info() is a logging macro, equivalent to printk(KERN_INFO ...)
static int __init hello_init(void)
{
        pr_info("Hello world init\n");
        return 0;
}

// This is the cleanup function. It runs when the module is removed with rmmod.
// __exit is a macro indicating this function is only used at exit time.
static void __exit hello_exit(void)
{
        pr_info("bye bye world\n");
}

// These macros register your init and exit functions with the kernel.
module_init(hello_init);
module_exit(hello_exit);

// Specifies the module's license. Required to avoid tainting the kernel.
//GPL is GNU General Public License (GPL) or open-source.
MODULE_LICENSE("GPL");
// Specifies the module author(ME).
MODULE_AUTHOR("DK");
// A short description of the module, visible via modinfo.
MODULE_DESCRIPTION("THIS IS HELLO WORLD MODULE");

