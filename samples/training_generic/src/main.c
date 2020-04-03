/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <drivers/sensor.h>

/*
 * The zephyr convention is that a devicetree node's "label" property,
 * as a string, is how a device is looked up at runtime.
 *
 * This type of lookup is convenient for development but increases
 * flash footprint and wastes some cycles during lookup, so other ways
 * to go from devicetree to device are being developed. It's how things
 * work today, though.
 */
#define MY_SENSOR_NAME DT_ALIAS_MY_SENSOR_LABEL

void main(void)
{
	struct device *sensor_device;
	struct sensor_value temperature;
	int err;
	unsigned int i = 0;

	printk("NCS application main() started.\n");

	sensor_device = device_get_binding(MY_SENSOR_NAME);
	if (sensor_device == NULL) {
		printk("No device named %s\n", MY_SENSOR_NAME);
		return;
	}

	printk("Found sensor %s\n", MY_SENSOR_NAME);

	while (1) {
		k_sleep(K_MSEC(1000));

		err = sensor_sample_fetch(sensor_device);
		if (err < 0) {
			printk("Can't read sensor: %d\n", err);
			return;
		}

		err = sensor_channel_get(sensor_device,
					 SENSOR_CHAN_AMBIENT_TEMP,
					 &temperature);
		if (err < 0) {
			printk("Can't get sensor value: %d\n", err);
			return;
		}

		printk("Temperature reading %d: %d.%d °C\n",
		       i, temperature.val1, temperature.val2);

		i++;
	}
}
