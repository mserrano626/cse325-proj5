/*Source File:  pit.c
 *Project Name: Project 4
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */
#include "pit.h"
#include "support_common.h"



unsigned int timer;


void pit0_init(){
	MCF_PIT0_PCSR = 0x0A1E;
	MCF_PIT0_PMR = 58593;//0x1E;    //30
	
	MCF_PIT0_PCSR |= MCF_PIT_PCSR_EN;
	/*
        MCF_PIT0_PCSR &= ~(MCF_PIT_PCSR_EN);
        MCF_PIT0_PCSR |= MCF_PIT_PCSR_RLD;
        MCF_PIT0_PCSR |= MCF_PIT_PCSR_PIF;
        MCF_PIT0_PCSR |= MCF_PIT_PCSR_PIE;
        MCF_PIT0_PCSR |= MCF_PIT_PCSR_OVW;
        MCF_PIT0_PCSR |= MCF_PIT_PCSR_DBG;
        MCF_PIT0_PCSR |= MCF_PIT_PCSR_PRE(13);
        
              
        timer = MCF_PIT0_PMR;
        //enable
        MCF_PIT0_PCSR |= MCF_PIT_PCSR_EN;
        */
}
void pit0_enable(){
	 MCF_PIT0_PCSR |= 0x1;
}
void pit_off() {
        //clear PCSR0[0] EN bit
        MCF_PIT0_PCSR &= ~(0x0001);
}