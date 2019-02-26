# Documentation

## What is a kernel module?
Modules are pieces of code that can be loaded and unloaded into the kernel upon demand. They extend the functionality of the kernel without the need to reboot the system. For example, one type of module is the device driver, which allows the kernel to access hardware connected to the system. Without modules, we would have to build monolithic kernels and add new functionality directly into the kernel image. Besides having larger kernels, this has the disadvantage of requiring us to rebuild and reboot the kernel every time we want new functionality.

## Functions and Macros used
Many parts of the kernel are well served as a module (dynamically-loadable parts of the kernel).
Using the module\_init() and module\_exit() macros it is easy to write code without #ifdefs which can operate both as a module or built into the kernel.

The following functions/macros were used while writing the kernel module.
1. \_\_**initcall()/module**\_**init() include/linux/init.h**
The module\_init() macro defines which function is to be called at module insertion time (if the file is compiled as a module), or at boot time: if the file is not compiled as a module the module\_init() macro becomes equivalent to \_\_initcall(), which through linker magic ensures that the function is called on boot.

	The function can return a negative error number to cause module loading to fail (unfortunately, this has no effect if the module is compiled into the kernel). This function is called in user context with interrupts enabled, so it can sleep.

2. **module**\_**exit() include/linux/init.h**
This macro defines the function to be called at module removal time (or never, in the case of the file compiled into the kernel). It will only be called if the module usage count has reached zero. This function can also sleep, but cannot fail: everything must be cleaned up by the time it returns.

	Note that this macro is optional: if it is not present, your module will not be removable (except for 'rmmod -f').

3. **printk() include/linux/kernel.h**
printk() feeds kernel messages to the console, dmesg, and the syslog daemon. It is useful for debugging and reporting errors, and can be used inside interrupt context, but use with caution: a machine which has its console flooded with printk messages is unusable. It uses a format string mostly compatible with ANSI C printf, and C string concatenation to give it a first "priority" argument:

	printk(KERN\_INFO "i = %u\n", i);
   
	See include/linux/kernel.h; for other KERN_ values; these are interpreted by syslog as the level. Special case: for printing an IP address use

   		_\_be32 ipaddress; 
		printk(KERN\_INFO "my ip: %pI4\n", &ipaddress);
      
	printk() internally uses a 1K buffer and does not catch overruns

4. **MODULE**\_**LICENCE**
In kernel 2.4 and later, a mechanism was devised to identify code licensed under the GPL (and friends) so people can be warned that the code is non open-source. This is accomplished by the MODULE\_LICENSE() macro. By setting the license to GPL, the "no license" warning will not be printed.
