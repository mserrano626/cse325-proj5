/*Source File:  gpio.c
 *Project Name: Project 5
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */

#include "gpio.h"

void gpio_init(){
	//set up port QS for primary function QSPI
	//MCF_GPIO_PQSPAR = MCF_GPIO_PQSPAR_PQSPAR0(MCF_GPIO_PQSPAR_QSPI_DOUT_DOUT)| 
	//		MCF_GPIO_PQSPAR_PQSPAR2(MCF_GPIO_PQSPAR_QSPI_CLK_CLK);
	
	MCF_GPIO_PQSPAR = 0x0011;
	MCF_GPIO_PORTQS = 0x05;
	//set up port TH for GPIO for output to led Matrix
	//MCF_GPIO_PTHPAR = MCF_GPIO_PTHPAR_PTHPAR6(0x1000)|
	//		MCF_GPIO_PTHPAR_PTHPAR7(0x4000);
	
	MCF_GPIO_PTHPAR = 0x0000;
	//set up QS 
	//MCF_GPIO_PORTQS = MCF_GPIO_PORTQS_PORTQS0 |
			//MCF_GPIO_PORTQS_PORTQS2;
	
	MCF_GPIO_DDRQS = 0x05;//MCF_GPIO_DDRQS_DDRQS0 | MCF_GPIO_DDRQS_DDRQS2;
	
	//TH as output
	//MCF_GPIO_PORTTH = MCF_GPIO_PORTTH_PORTTH6 |
			//MCF_GPIO_PORTTH_PORTTH7;
	
	
	//MCF_GPIO_DDRTH = MCF_GPIO_DDRTH_DDRTH6 |
	//		MCF_GPIO_DDRTH_DDRTH7;
	
	MCF_GPIO_DDRTH = 0xC0;
	
}
