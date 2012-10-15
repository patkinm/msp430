/*
 * lcd16.h
 *
 *  Created on: Dec 1, 2011
 *      Author: Gaurav www.circuitvalley.com
 */
/////////////////////////////////////////////////
/*
MCU PIN Number 	LCD PIN Number 	FUNCTION
PORT1.0 Pin 1 	11 	D4
PORT1.1 Pin 2 	12 	D5
PORT1.2 Pin 3	13 	D6
PORT1.3 Pin 4 	14 	D7
PORT1.6 Pin 8 	6 	EN
PORT1.7 Pin 9  	4 	RS
*/
#pragma once
#include <math.h>

//#pragme once
#ifndef LCD16_H_
#define LCD16_H_


//#include <msp430g2211.h>
#include <msp430g2553.h>

#include "stdafx.h"     
//#define  EN BIT6
//#define  RS BIT7
#define  EN BIT5
#define  RS BIT4

void waitlcd(unsigned int x);
void clear();
void clear(int row);
void lcdinit();
void integerToLcd(int integer );
void lcdData(unsigned char l);

void prints(char *s);
void prints(int i);
void prints(uint i);
void prints(float f);
void gotoXy(unsigned char  x,unsigned char y);
#endif /* LCD16_H_ */
