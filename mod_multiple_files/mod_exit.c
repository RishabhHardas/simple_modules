/*
This file contains the exit function
*/

#include <linux/kernel.h>
#include <linux/module.h>

void exit_module(void)
{
	printk(KERN_ALERT "In exit!\n");
}

module_exit(exit_module);

