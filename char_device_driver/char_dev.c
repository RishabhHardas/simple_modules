#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

struct file_operations fops = {
	read: device_read,
	write: device_write
};

int __init char_dev_entry(void)
{

}

void __exit char_dev_exit(void)
{

}

module_init(char_dev_init);
module_exit(char_dev_exit);

MODULE_AUTHOR("Rishabh Hardas");
MODULE_DESCRIPTION("Simple Char device driver");
