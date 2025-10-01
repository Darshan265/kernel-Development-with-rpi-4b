#include <linux/init.h>       // Required for module init/exit macros
#include <linux/module.h>     // Core header for modules
#include <linux/kernel.h>     // For KERN_INFO and printk/pr_info

MODULE_LICENSE("GPL");        // Declares that this module is licensed under GPL
MODULE_AUTHOR("DK");          // Module author name
MODULE_DESCRIPTION("Hello World Module with Parameters");  // Brief description of the module

static int count = 1;         // Declare an integer parameter with a default value of 1
static char *name = "RaspberryPi"; // Declare a string (char pointer) parameter with default value

module_param(count, int, 0644);    // Registers 'count' as a module parameter of type int
                                   // 0644 sets the permission (readable/writable by root, readable by others)
MODULE_PARM_DESC(count, "Number of times to print hello"); // Description for 'count'

module_param(name, charp, 0644);   // Registers 'name' as a module parameter of type charp (string)
MODULE_PARM_DESC(name, "Name to greet"); // Description for 'name'

static int __init hello_init(void) // Initialization function – runs on module insertion
{
    int i;
    for (i = 0; i < count; i++) {  // Loop from 0 to count - 1
        pr_info("Hello %s! [%d/%d]\n", name, i+1, count); // Print greeting message
    }
    return 0; // Success
}

static void __exit hello_exit(void) // Cleanup function – runs on module removal
{
    pr_info("Goodbye %s\n", name); // Print goodbye message
}

module_init(hello_init);  // Macro to register init function with the kernel
module_exit(hello_exit);  // Macro to register exit function with the kernel
