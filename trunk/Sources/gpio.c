/*
 * gpio.c
 *
 *  Created on: Apr 4, 2013
 *      Author: maserra3
 */

#include "gpio.h"

void gpio_init(){
	//set up port QS for primary function QSPI
	MCF_GPIO_PQSPAR = MCF_GPIO_PQSPAR_PQSPAR0(MCF_GPIO_PQSPAR_QSPI_DOUT_DOUT)| 
			MCF_GPIO_PQSPAR_PQSPAR2(MCF_GPIO_PQSPAR_QSPI_CLK_CLK);
	
	//set up port TH for GPIO for output to led Matrix
	MCF_GPIO_PTHPAR = MCF_GPIO_PTHPAR_PTHPAR6(0)|
			MCF_GPIO_PTHPAR_PTHPAR7(0);
	//set up QS 
	MCF_GPIO_PORTQS = MCF_GPIO_PORTQS_PORTQS0 |
			MCF_GPIO_PORTQS_PORTQS2;
	
	MCF_GPIO_DDRQS = MCF_GPIO_DDRQS_DDRQS0 | MCF_GPIO_DDRQS_DDRQS2;
	
	//TH as output
	MCF_GPIO_PORTTH = MCF_GPIO_PORTTH_PORTTH0 |
			MCF_GPIO_PORTTH_PORTTH1;
	
	MCF_GPIO_DDRTH = MCF_GPIO_DDRTH_DDRTH0 |
			MCF_GPIO_DDRTH_DDRTH1;
	
	
	
}

void set_portTH(int n){
	if (n == 0){ //case LEDM_STR high
		MCF_GPIO_SETTH |= 1 << MCF_GPIO_SETTH_SETTH6;
	}
	if (n == 1){
		MCF_GPIO_SETTH |= 0 << MCF_GPIO_SETTH_SETTH6;
	}
	
	
}
