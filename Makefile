obj-m := mod_param.o
        KERNELDIR =/lib/modules/$(shell uname -r)/build
        PWD :=$(shell pwd)

main:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

      
