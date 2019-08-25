#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>

int my_open (struct inode *iNode, struct file *myFile)
{
	printk(KERN_ALERT "Inside %s function \n", __FUNCTION__);
	return 0;	
}
ssize_t my_read (struct file *myFile, char __user *user, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "Inside %s function \n", __FUNCTION__);
	return 0;
}

ssize_t my_write (struct file *myFile, const char __user *user, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "Inside %s function \n", __FUNCTION__);
	return 0;
}
int my_close (struct inode *iNode, struct file *myFile)
{
	printk(KERN_ALERT "Inside %s function \n", __FUNCTION__);
	return 0;	
}

struct file_operations file_operations_dr = {
	.owner = THIS_MODULE,
	.open = my_open,
	.read = my_read,
	.write = my_write,
	.release = my_close,	
};

struct cdev cDev;

int char_driver_entry(void)
{
        printk(KERN_ALERT "Inside %s function \n", __FUNCTION__);
        int ret = register_chrdev_region(240,0,"so2c_dev" );
        if(ret<0)
        {
                printk(KERN_ALERT "Couldnt register char device");
                return ret;
        }
	cdev_init(&cDev, &file_operations_dr);
	cdev_add(&cDev,MKDEV(240,0), 1);
	return 0;
}

void char_driver_exit(void)
{
        printk(KERN_ALERT "Inside %s function \n", __FUNCTION__);
        unregister_chrdev_region(240,0 );
}

module_init(char_driver_entry);
module_exit(char_driver_exit);


