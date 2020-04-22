#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>

#define DEVICE_NAME "hello_char"

#define CLASS_NAME "chardev"

//Global variable for first
//device driver number
static dev_t first;

//Global variable for character device struct
static struct cdev c_dev;

//Global variable for device class
static struct class *cl;

static int chardev_open(struct inode *i, struct file *f)
{
    printk("Char device opened!\n");
    return 0;
}

static int chardev_close(struct inode *i, struct file *f)
{
    printk("Char device closed!\n");
    return 0;
}

static ssize_t chardev_read(struct file *f, char __user *buf,
                            size_t len, loff_t *off)
{
    printk("Char device read!\n");
    return len;
}

static ssize_t chardev_write(struct file *f, const char __user *buf,
                            size_t len, loff_t *off)
{
    printk("Char device write!\n");
    return 0;
}

struct file_operations fops = {
    owner: THIS_MODULE,
    open: chardev_open,
    release: chardev_close,
	read: chardev_read,
	write: chardev_write
};

int __init char_dev_init(void)
{
    printk("Hello char driver!\n");
    
    //Register a range of char device number
    //baseminor = 0, count =1, name = hello_char
    if (alloc_chrdev_region(&first, 0, 1, DEVICE_NAME) < 0) {
        return -1;
    }

    //Create a struct class structure
    if ((cl = class_create(THIS_MODULE, CLASS_NAME)) == NULL) {
        unregister_chrdev_region(first, 1);
        return -1;
    }

    if (device_create(cl, NULL, first, NULL, DEVICE_NAME) == NULL)
	{
	    class_destroy(cl);
	    unregister_chrdev_region(first, 1);
	    return -1;
	}

    cdev_init(&c_dev, &fops);

    if (cdev_add(&c_dev, first, 1) == -1) {
        device_destroy(cl, first);
        class_destroy(cl);
        unregister_chrdev_region(first, 1);
        return -1;
    }

    return 0;

}

void __exit char_dev_exit(void)
{
    printk("Char device exit!\n");
    
    cdev_del(&c_dev);
    device_destroy(cl, first);
    class_destroy(cl);
    unregister_chrdev_region(first, 1);
}

module_init(char_dev_init);
module_exit(char_dev_exit);

MODULE_AUTHOR("Rishabh Hardas");
MODULE_DESCRIPTION("Simple Char device driver");
MODULE_LICENSE("GPL");  
