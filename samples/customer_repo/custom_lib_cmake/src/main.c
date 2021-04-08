/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>
#include <multiply.h>

void main(void)
{
	printk("Hello World! %s\n", CONFIG_BOARD);
	int x = 5;
	int y = 2;
	int result = multiply(x, y);
	printk("%d times %d equals %d\n", x, y, result);
}
