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
#include <linux/of_gpio.h>
#include <linux/semaphore.h>
#include <linux/timer.h>
#include <linux/i2c.h>
#include <linux/fs.h>
#include <asm/mach/map.h>
#include <asm/uaccess.h>
#include <asm/io.h>

static const int AP3216_SYSTEMCONFIG = 0x00;  /* config reg */
static const int AP3216_INTSTATUS = 0x01;
static const int AP3216_INTCLEAR = 0x02;
static const int AP3216_IRDATALOW = 0x0a;
static const int AP3216_IRDATAHIGH = 0x0b;
static const int AP3216_ALSDATALOW = 0x0c;
static const int AP3216_ALSDATAHIGH = 0x0d;
static const int AP3216_PSDATALOW = 0x0e;
static const int AP3216_PSDATAHIGH = 0x0f;

static const int AP3216_COUNT = 1;
static const char* const AP3216_NAME = "ap3216";

struct ap3216_dev {
    dev_t devid;
    struct cdev cdev;
    struct class *class;
    struct device *device;
    struct device_node *nd;
    void *private_data;
    /* sensor relative */
    unsigned short ir;
    unsigned short als;
    unsigned short ps;
};

static struct ap3216_dev ap3216;

static int ap3216_read_regs(struct ap3216_dev *dev, u8 reg, void *buf, int len) {
		struct i2c_msg msg[2];
		struct i2c_client *client = dev->private_data;

		msg[0].addr = client->addr;
		msg[0].flags = 0;
		msg[0].buf = &reg;
		msg[0].len = 1;
		
		msg[1].addr = client->addr;
		msg[1].flags = I2C_M_RD;
		msg[1].buf = buf;
		msg[1].len = len;

		int ret = i2c_transfer(client->adpater, msg, 2);
		if (ret == 2) {
				return 0;
		}
		printk("i2c device: failed to read, ret=%d, reg=%06x, len=%d\n", ret, reg, len);
		return -EREMOTEIO;
}

static s32 ap3216_write_regs(struct ap3216_dev *dev, u8 reg, u8 *buf, u8 len) {
		if (len >= 256) {
				printk("failed to write regs, len exceeds the max with %d\n", len);
				return -1;
		}
		u8 write_buf[256];
		struct i2c_msg msg;
		struct i2c_client *client = dev->private_data;

		write_buf[0] = reg;
		memcpy(&write_buf[1], buf, len);

		msg.addr = client->addr;
		msg.flags = 0;
		msg.buf = write_buf;
		msg.len = len + 1;

		return i2c_transfer(client->adapter, &msg, 1);
}

static unsigned char ap3216_read_reg(struct ap3216_dev *dev, u8 reg) {
		u8 data = 0;
		ap3216_read_regs(dev, reg, &data, 1);
		return data;
}

static void ap3216_write_reg(struct ap3216_dev *dev, u8 reg, u8 data) {
		ap3216_write_regs(dev, reg, &data, 1);
}

static void ap3216_retrieve_data(struct ap3216_dev *dev) {
		int i = 0;
		unsigned char buf[6] = {0};

		for (; i != 6; ++i)
				buf[i] = ap3216_read_reg(dev, AP3216_IRDATALOW + i);

		/* hardware specified */
		if (buf[0] & 0x80)
				dev->ir = 0;
		else
				dev->ir = (((unsigned short)buf[1]) << 2) | (buf[0] & 0x03);

		dev->als = (((unsigned short)buf[3]) << 8) | buf[2];

		if (buf[4] & 0x40)
				dev->ps = 0;
		else
				dev->ps = ((unsigned short)(buf[5] & 0x3f) <<4) | (buf[4] & 0x0f);
}



static int ap3216_open(struct inode *inode, struct file *filp)
{
    filp->private_data = &ap3216;
		ap3216_write_reg(&ap3216, AP3216_SYSTEMCONFIG, 0x04);
		mdelay(50);
		ap3216_write_reg(&ap3216, AP3216_SYSTEMCONFIG, 0x03);
    return 0;
}

static ssize_t ap3216_read(struct file *filep, char __user *buf, size_t count, loff_t *off)
{
		short data[3] = {0};
		long err = 0;
		struct ap3216_dev *dev = filep->private_data;
		ap3216_retrieve_data(dev);
		data[0] = dev->ir;
		data[1] = dev->als;
		data[2] = dev->ps;
		err = copy_to_user(buf, data, sizeof(data));
    return sizeof(data);
}

static int ap3216_release(struct inode *inode, struct file *filep)
{
    return 0;
}

static struct file_operations ap3216_fops = {
    .owner = THIS_MODULE,
    .open = ap3216_open,
    .read = ap3216_read,
    .release = ap3216_release,
};

static int ap3216_probe(struct i2c_client *client, const struct i2c_device_id *id) {
		alloc_chrdev_region(&ap3216.cdev, AP3216_COUNT, AP3216_NAME);

		cdev_init(&ap3216, &ap3216_fops);
		cdev_add(&ap3216, ap3216.devid, AP3216_COUNT);

		ap3216.class = class_create(AP3216_NAME);
		if (IS_ERR(ap3216.class))
				return PTR_ERR(ap3216.class);

		ap3216.device = device_create(ap3216.class, NULL, ap3216.devid, NULL, AP3216_NAME);
		if (IS_ERR(ap3216.device))
				return PTR_ERR(ap3216.device);
		ap3216.private_data = client;

		return 0;
}

static int ap3216_remove(struct i2c_client *client) {
		device_destroy(ap3216.class, ap3216.devid);
		cdev_del(&ap3216.cdev);
		class_unregister(ap3216.class);
		class_destroy(ap3216.class);
		unregister_chrdev_region(ap3216.devid, AP3216_COUNT);
		return 0;
}

static const struct i2c_device_id ap3216_id[] = {
		{"bbb,ap3216", 0},
		{}
};

static const struct of_device_id ap3216_of_match[] = {
		{ .compatible = "bbb,ap3216" },
		{}
};

struct const struct i2c_driver ap3216_driver = {
		.probe = ap3216_probe,
		.remove = ap3216_remove,
		.driver = {
				.owner = THIS_MODULE,
				.name = "ap3216",
				.of_match_table = ap3216_of_match,
		},
		.id_table = ap3216_id,
};


module_i2c_driver(ap3216_driver);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("wujing");
