#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <uapi/linux/stat.h>


char *my_str = "Burrrp!";
int my_int = 1;


int my_param_set_int(const char *val, const struct kernel_param *kp)
{
	int res = 0;
	printk(KERN_ALERT "In my set int function\n");
	res = param_set_int(val, kp);
	return res;
}

static struct kernel_param_ops module_param_ops = {
	.set = my_param_set_int,
	.get = param_get_int,
};

module_param(my_str, charp, S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(my_str, "String parameter");

//module_param(my_int, int, S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP);
//MODULE_PARM_DESC(my_int, "Int Param");

module_param_cb(something, &module_param_ops, &my_int, S_IRUSR|S_IWUSR); 

int __init hello_init(void)
{
	printk(KERN_ALERT "Hello World!\n");
	printk(KERN_ALERT "The string is -> %s\n", my_str);
	printk(KERN_ALERT "The int is %d\n", my_int);
	return 0;
}

void __exit hello_exit(void)
{
	printk(KERN_ALERT "The string is -> %s\n", my_str);
	printk(KERN_ALERT "THe int is %d\n", my_int);
	printk("Exit!\n");
}


module_init(hello_init);
module_exit(hello_exit);
MODULE_AUTHOR("Rishabh Hardas");
MODULE_DESCRIPTION("Sting args and callback demo");
