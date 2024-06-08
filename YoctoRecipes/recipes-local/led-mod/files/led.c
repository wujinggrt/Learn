/******************************************************************************
 *
 *   Copyright (C) 2011  Intel Corporation. All rights reserved.
 *
 *   SPDX-License-Identifier: GPL-2.0-only
 *
 *****************************************************************************/

#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <asm/mach/map.h>
#include <asm/uaccess.h>
#include <asm/io.h>

static const char* LED_NAME = "myled";

// static int LED_MAJOR = 0;
static dev_t LED_DEV = 0;
static const int LED_DEVICE_COUNT = 1;

enum LedState {
	LEDOFF, LEDON
};

/*
 * @param - state : LEDON, LEDOFF
 */
static void led_switch(enum LedState s)
{
	// u32 value = 0;
	switch (s) {
		case LEDOFF: {
			pr_info("led switch LEDOFF\n");
			break;
		}
		case LEDON: {
			pr_info("led switch LEDON\n");
			break;
		}
	}
}

static int __init hello_init(void)
{
	int r = alloc_chrdev_region(&LED_DEV, 0, LED_DEVICE_COUNT, LED_NAME);
	if (r < 0) {
		pr_err("Failed to alloc chrdev region\n");
		return r;
	}
	pr_info("Hello World!\n");
	return 0;
}

static void __exit hello_exit(void)
{
	unregister_chrdev_region(LED_DEV, LED_DEVICE_COUNT);
	pr_info("Goodbye Cruel World!\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
