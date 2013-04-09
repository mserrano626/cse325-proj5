/*
 * main implementation: use this sample to create your own application
 *
 */


#include "support_common.h" /* include peripheral declarations and more */
#include "global.h"


__declspec(noreturn)int main(void)
{

	gpio_init();
	qspi_init();
	pit0_init();
	led_matrix_init();
	led_write_row();
	interupt_config(55, 4, 6, pit0_isr);
	int_uninhibit_all();
	
	
	for(;;) {	   
		//led_refresh();
	}
}
