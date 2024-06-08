/******************************************************************************
 *
 *   Copyright (C) 2011  Intel Corporation. All rights reserved.
 *
 *   SPDX-License-Identifier: GPL-2.0-only
 *
 *****************************************************************************/

#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <linux/fs.h>
#include <asm/mach/map.h>
#include <asm/uaccess.h>
#include <asm/io.h>

const int GPIOLED_COUNT = 1;
const char* const GPIOLED_NAME = "mygpioled";
const int LEDOFF = 0;
const int LEDON = 1;

struct mygpioled_device {
    dev_t devid;
    struct cdev cdev;
    struct class *class;
    struct device *device;
    struct device_node *nd;
    int gpio_id;
};

static struct mygpioled_device mygpioled;

static int mygpioled_open(struct inode *inode, struct file *filp)
{
    filp->private_data = &mygpioled;
    return 0;
}

static ssize_t mygpioled_read(struct file *filep, char __user *buf, size_t count, loff_t *off)
{
    return 0;
}

static ssize_t mygpioled_write(struct file *filep, const char __user *buf, size_t count, loff_t *off)
{
    unsigned char data[1];
    unsigned char state;
    struct mygpioled_device *dev = filep->private_data;

    int ok = copy_from_user(data, buf, count);
    if (ok < 0) {
        printk("kernel write failed!\r\n");
        return -EFAULT;
    }

    state = data[0];
    // GPIO low active
    gpio_set_value(dev->gpio_id, state == LEDON ? 0 : 1);
    return 0;
}

static int mygpioled_release(struct inode *inode, struct file *filep)
{
    return 0;
}

static struct file_operations mygpioled_fops = {
    .owner = THIS_MODULE,
    .open = mygpioled_open,
    .read = mygpioled_read,
    .write = mygpioled_write,
    .release = mygpioled_release,
};

static int __init mygpioled_init(void)
{
    mygpioled.nd = of_find_node_by_path("/mygpioled");
    if (!mygpioled.nd) {
        printk("could not find mygpioled node\r\n");
		return -EINVAL;
    }
    printk("we have found mygpioled node\r\n");

    // gpios 是在 mygpioled 节点的属性。
    mygpioled.gpio_id = of_get_named_gpio(mygpioled.nd, "gpios", 0);
    if (mygpioled.gpio_id < 0) {
        printk("could not get led-gpio");
        return -EINVAL;
    }
    printk("we have found led-gpio[num=%d]\r\n", mygpioled.gpio_id);

    if (gpio_direction_output(mygpioled.gpio_id, 1) < 0) {
        printk("could not set gpio\r\n");
    }

    alloc_chrdev_region(&mygpioled.devid, 0, GPIOLED_COUNT, GPIOLED_NAME);
    printk("mygpioled major=%d,minor=%d\r\n", MAJOR(mygpioled.devid), MINOR(mygpioled.devid));

    mygpioled.cdev.owner = THIS_MODULE;
    cdev_init(&mygpioled.cdev, &mygpioled_fops);

    cdev_add(&mygpioled.cdev, mygpioled.devid, GPIOLED_COUNT);

    // new version removes the parameter of owner.
    // mygpioled.class = class_create(THIS_MODULE, GPIOLED_NAME);
    mygpioled.class = class_create(GPIOLED_NAME);
    if (IS_ERR(mygpioled.class)) {
        return PTR_ERR(mygpioled.class);
    }

    mygpioled.device = device_create(mygpioled.class, NULL, mygpioled.devid, NULL, GPIOLED_NAME);
    if (IS_ERR(mygpioled.device)) {
        return PTR_ERR(mygpioled.device);
    }

    return 0;
}

static void __exit mygpioled_exit(void)
{
    device_destroy(mygpioled.class, mygpioled.devid);
    cdev_del(&mygpioled.cdev);
    class_unregister(mygpioled.class);
    class_destroy(mygpioled.class);
    unregister_chrdev_region(mygpioled.devid, GPIOLED_COUNT);

}

module_init(mygpioled_init);
module_exit(mygpioled_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("wujing");
