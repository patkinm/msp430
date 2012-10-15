/*
 * lcd16.c
 *
 *  Created on: Dec 1, 2011
 *      Author: Gaurav www.circuitvalley.com
 */

#include "lcd16.h"

void lcdcmd(unsigned char Data)
{

    P2OUT &= ~RS; //because sending command
    P2OUT  &=~EN;

    P2OUT &= 0xF0;
    P2OUT |= ((Data >> 4) & 0x0F);
    P2OUT  |=EN;
    waitlcd(2);
    P2OUT  &=~EN;

    P2OUT &= 0xF0;
    P2OUT  |= (Data & 0x0F);
    P2OUT  |=EN;
    waitlcd(2);
    P2OUT  &=~EN;


}
void lcdData(unsigned char l)
{
    P2OUT |=RS;  //because sending data
    P2OUT  &=~EN;
    P2OUT &= 0xF0;
    P2OUT |=((l >> 4) & 0x0F);

    P2OUT  |=EN;
    waitlcd(2);
    P2OUT  &=~EN;
    P2OUT &=  0xF0;
    P2OUT  |= (l & 0x0F);
    P2OUT  |=EN;
    waitlcd(2);
    P2OUT  &=~EN;



}


char* FloatToCharPointer(float data)   
{
    int pint = (int) data;
    int pfract = (int)((data - pint) * 1000);
    static char string[7];
    pint = abs(pint);
    pfract = abs(pfract);
    
    sprintf(string, "%d.%d", pint, pfract);

    return string;
}

void lcdinit(void)
{
    P2DIR = 0xFF;
    P2OUT = 0x00;
    
    P2OUT &=~RS;
    P2OUT  &=~EN;
    P2OUT |= 0x3;
    waitlcd(40);
    P2OUT  |=EN;
    P2OUT  &=~EN;
    waitlcd(5);
    P2OUT  |=EN;
    P2OUT  &=~EN;
    waitlcd(5);
    P2OUT  |=EN;
    P2OUT  &=~EN;
    waitlcd(2);

    P2OUT &= 0xF2;
    P2OUT  |=EN;
    P2OUT  &=~EN;
    lcdcmd(0x28);   //set data length 4 bit 2 line
    waitlcd(250);
    lcdcmd(0x0E);   // set display on cursor on blink on
    waitlcd(250);
    lcdcmd(0x01); // clear lcd
    waitlcd(250);
    lcdcmd(0x06);  // cursor shift direction
    waitlcd(250);
    lcdcmd(0x80);  //set ram address
    waitlcd(250);
}

void waitlcd(volatile unsigned int x)
{
    volatile unsigned int i;
//for (x; x > 1; x--)
//{
    for (i=0;i<=110;i++);
//}
}

void prints(char *s)
{

  while (*s)
    {
       lcdData(*s);
       s++;
    }
}
void prints(int i)
{
    integerToLcd(i);
};

void prints(uint i)
{
    prints(static_cast<int>(i));
};

void prints(float f)
{
    prints(FloatToCharPointer(f));
};

void gotoXy(unsigned char  x,unsigned char y)
{
   if(x<40)
   {
    if(y) x |= 0x40;
    x |=0x80;
    lcdcmd(x);
    }
}
void integerToLcd(int integer )
{

unsigned char thousands,hundreds,tens,ones;
thousands = integer / 1000;

    lcdData(thousands + 0x30);

	 hundreds = ((integer - thousands*1000)-1) / 100;

	lcdData( hundreds + 0x30);
tens=(integer%100)/10;

	lcdData( tens + 0x30);
	ones=integer%10;

	lcdData( ones + 0x30);
}

void clear(void)
{
    gotoXy(0, 0);
    prints("                ");
    gotoXy(0, 1);
    prints("                ");
}
void clear(int row)
{
    gotoXy(0, row);
    prints("                ");
}

