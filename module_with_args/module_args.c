/*
* The command line argument to the module should
* be provided while inserting the module
*
* Example:
* sudo insmod module_args sint_param=123
*/

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <uapi/linux/stat.h>

short int sint_param = 0;

module_param(sint_param, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(sint_param, "Simple short int argument");

int __init hello_init(void)
{
	printk(KERN_ALERT "Hello World!\n");
	printk(KERN_ALERT "Short int = %d\n", sint_param);
	return 0;
}

void __exit hello_exit(void)
{
	printk(KERN_ALERT "Exit\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rishabh Hardas");


