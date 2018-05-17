/*
* The simplest kernel module
*/
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kernel.h>

int __init hello_init(void)
{
	printk(KERN_INFO "Hello World!\n");
	return 0;
}

void __exit hello_exit(void)
{
	printk(KERN_INFO "Goodbye World!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Rishabh Hardas");
MODULE_DESCRIPTION("Simple 'Hello World' kernel module");
MODULE_LICENSE("GPL");
