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
	
	// 1010 0010 0010 1000
	//master on, 0 , 8 bits per transfer, 0, 0, baud = A0= 250khz transfer rate
	
	MCF_QSPI_QMR = 0xA0FF;
	
	//
	MCF_QSPI_QDLYR = 0x0000;
	
	//Disable all
	//QWR[ENDQP] and QWR[NEWQP] will be configured before transfer begins
	MCF_QSPI_QWR = 0x0000;
	
	
	//initialize QIR
	//clear all fields/ flags
	//QIR[SPIFE] -- enable interrupts following transfer of last datum
	MCF_QSPI_QIR = 0x010D;
	
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
	int transfer;
	int i;
	int QSPI_XMIT_RAM_BASE_ADDR = 0x00;
	int QSPI_CMD_RAM_BASE_ADDR = 0x20;
	
	//load data into ram
	// loads 8 bits at a time, 3 times
	for (i = 0; i < 3; i++){
		MCF_QSPI_QAR = (unsigned short)(QSPI_XMIT_RAM_BASE_ADDR + i);
		MCF_QSPI_QDR = (unsigned short)data[i];
	}
	//load commands into ram
	for (i = 0; i < 3; i++){
		MCF_QSPI_QAR = QSPI_CMD_RAM_BASE_ADDR + i;
		MCF_QSPI_QDR = 0x4F00;
	}
	
	//set start and end position pointers
	MCF_QSPI_QWR &= MCF_QSPI_QWR_NEWQP(0);
	MCF_QSPI_QWR |= MCF_QSPI_QWR_ENDQP(2);
	
	//initiate transfer
	MCF_QSPI_QDLYR |= 0x8000;
	
	
	transfer = MCF_QSPI_QIR | 0x0001;
	
	while((transfer)== 0){
		
	}
}


