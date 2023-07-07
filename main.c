#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint PIN_BTN = 2;

const uint PIN_SEG_A = 8;
const uint PIN_SEG_B = 9;
const uint PIN_SEG_C = 10;
const uint PIN_SEG_D = 11;
const uint PIN_SEG_E = 12;
const uint PIN_SEG_F = 13;
const uint PIN_SEG_G = 14;
const uint PIN_SEG_P = 15;

int bits[10] = {
	0x3f,
	0x06,
	0x5b,
	0x4f,
	0x66,
	0x6d,
	0x7d,
	0x07,
	0x7f,
	0x67
};


int main() {
	//bi_decl(bi_program_description("This is a program to blink 3 LEDs."));
	//bi_decl(bi_1pin_with_name(PIN_REDLED, "External Red LED"));
	//bi_decl(bi_1pin_with_name(PIN_YELLOWLED, "External Yellow LED"));
	//bi_decl(bi_1pin_with_name(PIN_GREENLED, "External Green LED"));
	
	stdio_init_all();
	
	gpio_init(PIN_BTN);
	gpio_set_dir(PIN_BTN, GPIO_IN);
	gpio_pull_up(PIN_BTN);
	
	gpio_init(PIN_SEG_A);
	gpio_set_dir(PIN_SEG_A, GPIO_OUT);
	//gpio_set_outover(PIN_SEG_A, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_B);
	gpio_set_dir(PIN_SEG_B, GPIO_OUT);
	//gpio_set_outover(PIN_SEG_B, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_C);
	gpio_set_dir(PIN_SEG_C, GPIO_OUT);
	//gpio_set_outover(PIN_SEG_C, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_D);
	gpio_set_dir(PIN_SEG_D, GPIO_OUT);
	//gpio_set_outover(PIN_SEG_D, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_E);
	gpio_set_dir(PIN_SEG_E, GPIO_OUT);
	//gpio_set_outover(PIN_SEG_E, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_F);
	gpio_set_dir(PIN_SEG_F, GPIO_OUT);
	//gpio_set_outover(PIN_SEG_F, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_G);
	gpio_set_dir(PIN_SEG_G, GPIO_OUT);
	//gpio_set_outover(PIN_SEG_G, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_P);
	gpio_set_dir(PIN_SEG_P, GPIO_OUT);
	//gpio_set_outover(PIN_SEG_P, GPIO_OVERRIDE_INVERT);
	
	while(1) {

		int32_t mask = bits[0];
		gpio_put_masked(0xff << PIN_SEG_A, mask << PIN_SEG_A);
		
		if(!gpio_get(PIN_BTN)) {
			puts("Button Pressed");
			for (int i = 0; i < 10; i++) {
				int32_t mask = bits[i];
				gpio_put_masked(0xff << PIN_SEG_A, mask << PIN_SEG_A);
				sleep_ms(1000);
			}
		}
	
	}
}
