#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>


void char_driver_entry()
{
        printk(KERN_ALERT "Inside %s function \n", __FUNCTION__);
        int ret = register_chrdev_region(240,0,"so2c_dev" );
        if(ret<0)
        {
                printk(KERN_ALERT "Couldnt register char device");
                return ret;
        }
        return 0;
}

void char_driver_exit()
{
        printk(KERN_ALERT "Inside %s function \n", __FUNCTION__);
        unregister_chrdev_region(240,0 );
        return 0;
}

module_init(char_driver_entry);
module_exit(char_driver_exit);


