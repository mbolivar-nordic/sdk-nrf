/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>

void main(void)
{
	/*
	 * printk() is a low level printf()-alike that's part of Zephyr.
	 * By default, it does polling UART output on nRF9160 DK.
	 */
	printk("NCS application main() started.\n");
	printk("Hello, Americas FAEs and sales!\n");
}
