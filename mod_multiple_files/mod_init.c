/*
* This file contains init funciton
*/
#include <linux/kernel.h>
#include <linux/module.h>

int __init module_entry(void)
{
	printk(KERN_ALERT "In init!\n");
	return 0;
}

module_init(module_entry);
