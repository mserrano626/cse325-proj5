/*
 * qspi.c
 *
 *  Created on: Apr 4, 2013
 *      Author: maserra3
 */

#include "qspi.h"

void qspi_init(){
	//try lowering frequency to 1Mhz
	//needs to send 24 bits at a time. 
	//str needs to be low. when turned high it moves all 
	//	the data in the registers to the output
	// str then needs to be returned to low
	//oe allows the output to be enabled on the board. 
	//	needs to be low for a few micro seconds for lights to be visible
	
	//baud rate is a pre divider
	//qspi needs to transmit 8 bit values
	
	// 1010 0000 0010 1000
	//master on, 0 , 8 bits per transfer, 0, 0, baud = 40= 1Mhz transfer rate
	MCF_QSPI_QMR = 0xA028;
	
	//
	MCF_QSPI_QDLYR = ~(0xFFFF);
	
	//Disable all
	//QWR[ENDQP] and QWR[NEWQP] will be configured before transfer begins
	MCF_QSPI_QWR = ~(0xFFFF);
	
	//initialize QIR
	//clear all fields/ flags
	//QIR[SPIFE] -- enable interupts following transfer of last datum
	MCF_QSPI_QIR = 0x0007;
	
	/*
	 * 
	 * int src = 18 + n
	 * write address of QSPI_ISR to exception vector table
	 * set interput level priority to ICR18
	 * clear mask bit 18 in IMRL
	 * 
	 */
	
}

void qspi_transmit(int data[]){
	int i;
	int QSPI_XMIT_RAM_BASE_ADDR = 0x00;
	int QSPI_CMD_RAM_BASE_ADDR = 0x20;
	
	for (i = 0; i <8; i++){
		MCF_QSPI_QAR = QSPI_XMIT_RAM_BASE_ADDR + i;
		MCF_QSPI_QDR = data[i];
	}
	for (i = 0; i <8; i++){
		MCF_QSPI_QAR = QSPI_CMD_RAM_BASE_ADDR + i;
		MCF_QSPI_QDR = 0x4000;
	}
	
	MCF_QSPI_QWR &= MCF_QSPI_QWR_NEWQP(0);
	MCF_QSPI_QWR |= MCF_QSPI_QWR_ENDQP(7);
	
	MCF_QSPI_QDLYR |= 0x8000;
	
	while((MCF_QSPI_QIR & MCF_QSPI_QIR_SPIF)== 0){
		
	}
}


