#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");

// Function to specify what happens when the module is loaded
static int myname_init(void)
{
	printk(KERN_ALERT "My name is MRINMAY MUKHERJEE\n"); //Include your name
	return 0;
}


// Function to specify what happens when the module is removed 
static void myname_exit(void)
{
	printk(KERN_ALERT "Exiting.... BYE!! \n");
}

// Specifying the functions to call during the init and removal of module
module_init(myname_init);
module_exit(myname_exit);
