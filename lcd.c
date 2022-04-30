#include<reg51.h>
#include"header.h"

sbit RS=P2^0;
sbit RW=P2^1;
sbit EN=P2^2;
//#define LCD P0;
 


void lcd_data(unsigned char d)
{
P0=d;
RS =1;
RW=0;
EN=1;
delay_ms(2);
EN=0;
}



void lcd_cmd(unsigned char c)
{
P0=c;
RS=0;
RW=0;
EN=1;
delay_ms(2);
EN=0;
}


void lcd_init(void)
{
lcd_cmd(0x2);
lcd_cmd(0x38);
lcd_cmd(0xE);
lcd_cmd(0x1);
}
 void lcd_string(unsigned char *d)
{
	while(*d)
	{
		lcd_data(*d++);
	}
}
