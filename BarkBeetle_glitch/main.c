#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/watchdog.h"
// #include "hardware/regs/glitch_detector.h"
#include "hardware/regs/powman.h"
#include "hardware/structs/powman.h"
#include "hardware/structs/otp.h"
#include "rp2350_playground.h"

#include "display/display.h"

#include <stdio.h>

#pragma GCC push_options
#pragma GCC optimize("O0")

// This part is for illustrative
// This glitch tree example is based on the tutorial example from https://github.com/hextreeio/rp2350-security-playground-demo/tree/main
// We set trigger pin at each target node and collect the first successful glitch parameter pair.
// We collect all the pairs sequentially
void __not_in_flash_func(glitch_path)()
{
	uint32_t label = 0;
	features[5] = {100.0f, 62.0f, 20.0f, -0.92f, 30.0f};
	// bool glitch_detector_triggered = (powman_hw->chip_reset & 0x04000000) != 0;

    if (features[0] < 129.0) {
		gpio_put(TRIGGER2_PIN, 1);
        if (features[4] < 28.0) {
			gpio_put(TRIGGER2_PIN, 0);
            if (features[2] < 30.16278) {
                label = 0;
            } else {
                label = 1; 
            }
        } else {
            if (features[2] < 26.565) {
                label = 2;
            } else {
                if (features[0] < 94.0) {
                    label = 3; 
                } else {               
                    if (features[3] < 0.54013) {
                        label = 4; 
                    } else {
                        label = 5; 
                    }
                }
            }
        }
    } else {

        if (features[2] < 29.71971) {
            label = 6; 
        } else {
            if (features[0] < 166.0) {
                if (features[1] < 61.0) {
                    label = 7; 
                } else {
                    if (features[4] < 31.0) {
                        label = 8; 
                    } else { 
                        label = 9; 
                    }
                }
            } else {
                label = 10;
            }
        }
    }

	watchdog_update();
	// Check for glitch
	if (label != 2) // correct label
	{
		watchdog_update();
		if (label == 0) // expected faulted label
		{
			uart_putc_raw(uart0, 'E');
		}
		else
		{
			uart_putc_raw(uart0, 'Q');
		}
		watchdog_update();
	}
	else
	{
		// N indicates regular execution
		uart_putc_raw(uart0, 'N');
	}
	watchdog_update();


	char buffer[12];
	snprintf(buffer, sizeof(buffer), "%u", label);
	uart_puts(uart0, buffer);
	watchdog_update();
}
#pragma GCC pop_options


int main()
{
	init_uart();

	watchdog_enable(100, 1);
	gpio_init(TRIGGER_PIN);
	gpio_set_dir(TRIGGER_PIN, GPIO_OUT);
	gpio_put(TRIGGER_PIN, 0);

	gpio_init(TRIGGER2_PIN);
	gpio_set_dir(TRIGGER2_PIN, GPIO_OUT);
	gpio_put(TRIGGER2_PIN, 0);

	glitch_detector_disarm();
	glitch_path();

	for (;;) { watchdog_update(); }
}
