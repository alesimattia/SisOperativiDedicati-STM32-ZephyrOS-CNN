// #include <kernel.h>
// #include <zephyr/kernel.h>
// #include <zephyr/device.h>
// #include <zephyr/devicetree.h>
// #include <zephyr/drivers/gpio.h>                                                                                                                                                     
// #include <zephyr/drivers/spi.h>
// #include <zephyr/drivers/display.h>
// #include <zephyr/drivers/sensor.h>
// #include <lvgl.h>
// #include <stdio.h>
// #include <string.h>
// #include <iostream>

#include <iostream>
#include "cppflow.h"

//using namespace std;

/* int main(int argc, char *argv[])
{
	int c = 0;
	printf("First Program\n");

	while(1){
		k_sleep(K_MSEC(1000));
		c++;
		printf("Running since %d seconds\n", c );
	}

	return 0; //required for Zephyr C++ implementation
} */

int main(int argc, char *argv[]) {

    // Create a tensor from a list, a = [1.0, 2.0, 3.0]
    auto a = cppflow::tensor({1.0, 2.0, 3.0});
    // Create a tensor of shape 3 filled with 1.0, b = [1.0, 1.0, 1.0]
    auto b = cppflow::fill({3}, 1.0);

    std::cout << a + b << std::endl;

    return 0;
}

