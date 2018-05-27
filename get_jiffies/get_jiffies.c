#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <uapi/linux/stat.h>
#include <linux/jiffies.h>

unsigned long ticks_now = 0;

int get_ticks (char *val, const struct kernel_param *kp)
{
	int res =0;
	ticks_now = jiffies;

	res = param_get_ulong(val, kp);
	
	return res;
}

static struct kernel_param_ops module_param_ops = {
	.get = get_ticks,
};

module_param_cb(get_jiffies, &module_param_ops, &ticks_now, S_IRUSR|S_IRGRP|S_IROTH);

int __init get_jiffies_entry(void)
{
	return 0;
}

void __exit get_jiffies_exit(void)
{

}

module_init(get_jiffies_entry);
module_exit(get_jiffies_exit)

MODULE_AUTHOR("Rishabh Hardas");
MODULE_DESCRIPTION("Module to get current count of jiffies");


