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
	
	
	//ISR for qspi
	//interupt_config(18, 4, 6, qspi_isr);
	for(;;) {	   
	   	
	}
}
