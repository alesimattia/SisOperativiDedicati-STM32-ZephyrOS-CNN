/*
 * Copyright (c) 2018 Bosch Sensortec GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>                                                                                                                                                     
#include <zephyr/drivers/spi.h>



int main(void)
{
	int c = 0;
	printf("First Program\n");

	while(1){
		k_sleep(K_MSEC(1000));
		c++;
		printf("Running since %d seconds\n", c );
	}
	return 0;
}
