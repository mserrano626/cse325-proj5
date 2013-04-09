/*Source File:  ledm.c
 *Project Name: Project 5
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */

#include "global.h"
#include "support_common.h"

typedef enum{
	black = 0x00,
	green = 0x01,
	orange = 0x02,
	red = 0x03	
}ledm_color;

int trans_data[3];
int green_col[8];
int red_col[8];
int matrix_row;




//int pattern1[8][8];
              /*  = {{0,0,0,2,2,0,0,0},
					{0,0,2,0,0,2,0,0},
					{0,2,0,0,0,0,2,0},
					{2,0,0,1,1,0,0,2},
					{2,0,0,1,1,0,0,2},
					{0,2,0,0,0,0,2,0},
					{0,0,2,0,0,2,0,0},
					{0,0,0,2,2,0,0,0}};*/

int pattern1[8][8] = {
                { black, black, black, green, green, black, black, black},
                { black, black, green, black, black, green, black, black},
                { black, green, black, black, black, black, green, black},
                { green, black, black, black, black, black, black, green},
                { green, black, black, black, black, black, black, green},
                { black, green, black, black, black, black, green, black},
                { black, black, green, black, black, green, black, black},
                { black, black, black, green, green, black, black, black}
};


void led_matrix_init(){
	
	int row;
	int col;
	
	for(row = 0; row < 8; row++){
		green_col[row] = 0x00;
		red_col[row] = 0x00;
		for(col = 0; col < 8; col++){
			if(pattern1[row][col] == red){
				red_col[row] = (1 << col) | red_col[row];
			}
			else if (pattern1[row][col] == green){
				green_col[row] = (1 << col) | green_col[row];
			} 
			else if (pattern1[row][col] == orange){
				red_col[row] = (1 << col) | red_col[row];
				green_col[row] = (1 << col) | green_col[row];
			}
			
		}
	}
	matrix_row = 0;
	/*
	//bit transfer = 8
	//message que = 3
	/*
	int testArray[2];

	testArray[0] = 0xFF;//red
	testArray[1] = 0xFF;//green
	testArray[2] = 0xFF;//row
	
	//pth6 = STR
	//pth7 = OE
	
	/* //correct transfer code
	MCF_GPIO_PORTTH = 0x80;//STR low, OE High
	qspi_transmit(testArray);
	
	MCF_GPIO_PORTTH = 0x40; //STR high, OE Low
	*/
	
	
}

void led_write_row(){
	trans_data[0] = 0;//red_col[matrix_row];
	trans_data[1] = green_col[matrix_row];
	trans_data[2] = ~(1 << matrix_row);
	
	MCF_GPIO_PORTTH = 0x80;//STR low, OE High
	qspi_transmit(trans_data);
	MCF_GPIO_PORTTH = 0x40; //STR high, OE Low
	
	
}

void led_refresh(){
	led_write_row();
	matrix_row = (matrix_row + 1) % 8;
	
	pit0_enable();
}
