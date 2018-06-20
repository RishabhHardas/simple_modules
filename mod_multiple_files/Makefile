obj-m += multi_file_mod.o
multi_file_mod-objs := mod_init.o mod_exit.o
KERNEL ?= /lib/modules/$(shell uname -r)/build

all:
	make -C $(KERNEL) M=$(PWD) modules

clean:
	make -C $(KERNEL) M=$(PWD) clean
