#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");


static int myname_init(void)
{
	printk(KERN_ALERT "My name is MRINMAY MUKHERJEE\n"); //Include your name
	return 0;
}


static void myname_exit(void)
{
	printk(KERN_ALERT "Exiting.... BYE!! \n");
}


module_init(myname_init);
module_exit(myname_exit);
