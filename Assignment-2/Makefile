ifneq ($(KERNELRELEASE),)
	obj-m := myname.o
else
	KERNELDIR ?= \
				 /lib/modules/`uname -r`/build/
	PWD := `pwd`
default:
	$(MAKE) -C $(KERNELDIR) \
		M=$(PWD) modules
endif
clean:
	rm -f *.ko *.o Module* *mod*
