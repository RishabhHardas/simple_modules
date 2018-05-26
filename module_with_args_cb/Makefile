obj-m += mod_args_cb.o
KERNEL ?= /lib/modules/$(shell uname -r)/build

all:
	make -C $(KERNEL) M=$(PWD) modules

clean:
	make -C $(KERNEL) M=$(PWD) clean
