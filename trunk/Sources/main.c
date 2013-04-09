/*Source File:  main.c
 *Project Name: Project 5
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */

#include "support_common.h" /* include peripheral declarations and more */
#include "global.h"


__declspec(noreturn)int main(void)
{

	gpio_init();
	qspi_init();
	pit0_init();
	led_matrix_init();
	//led_write_row();
	interupt_config(55, 4, 6, pit0_isr);
	int_uninhibit_all();
	
	
	for(;;) {	   
		//led_refresh();
	}
}
