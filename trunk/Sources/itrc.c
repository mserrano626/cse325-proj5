/*Source File:  itrc.c
 *Project Name: Project 5
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */

#include "itrc.h"
//#include "pit.h"
//#include "pwm.h"
//#include "note.h"
//#include "song.h"
#include "global.h"



extern uint32 __VECTOR_RAM[];

#define ICR_BASE (volatile uint8 *)(0x40000C40)

void interupt_config(int src, int level, int priority, isr_funct isr){
        volatile uint8 *icr;
        
        /* Write the address of the ISR (in p_isr) into the exception vector table at the proper offset from the beginning of the table.
        */
        __VECTOR_RAM[64 + src] = (uint32)isr;

        /* Write the level and priority for the interrupt source into the appropriate ICR register. */
        icr = (volatile uint8 *)(ICR_BASE + src);
        *icr = (uint8)(level << 3 | priority);

        /* Unmask interrupts from the interrupt source. */
        interupt_unmask_src(src);
}

void interupt_unmask_src(int src){
        /* The mask bits for interrupt sources 32-63 are in the IMRH registers. The mask bits for interrupt sources 1-31 are in the IMRL registers. Note, when clearing bits in IMRL it is important not to write 1 to IMRL[0] because this is the MASKALL bit.
        */

        if (src > 31) {
                MCF_INTC0_IMRH &= ~(1 << (src - 32));
        } 
        else {
                MCF_INTC0_IMRL &= ~(1 << src) & 0xFFFFFFFE;
        }
}

asm __declspec(standard_abi) void int_uninhibit_all(){
        
        move.w SR, d0
        andi.l #0xF8FF, d0
        move.w d0, SR
        rts
        
}

__declspec(interrupt) void pit0_isr(){

				led_refresh();
                //Clear pit 0 channel 0 interrupt request flag
                MCF_PIT0_PCSR |= 0x0004;

                //stop current note
                //note(0xFF, 0x03);

                //stop timer and reset
                //pit_off();

                // next row
                
}

__declspec(interrupt) void gpt0_isr()
{
        //Clear the interrupt request flag
        MCF_GPT_GPTFLG1 = 0x01;
        // This will change the song BPM
        //set_tempo();
        
}

//__declspec(interrput) void qspi_isr()
//{
	//interupt_config(18, 4, 6, isr_funct qspi_isr);
	//clear request flag
	//MCF_QSPI_QIR &= (~(0x1) << 8);
	
//}