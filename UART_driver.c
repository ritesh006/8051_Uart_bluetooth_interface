/* UART_driver.c */

#include <reg51.h>
#include "header.h"

void uart_init(unsigned int baudrate)
{
	/* UART initilization */
	SCON = 0X50;
	TMOD |= 0X20;
	TH1 = 253;     /* for baudrate of 9600 */
	TR1 = 1;       /* start baudrate settting */
	
	switch(baudrate)
	{
		case 7200 : TH1 = 252;
								break;
		
		case 9600 : TH1 = 253;
								break;
		
		case 14400: TH1 = 254;
								break;
		
		case 28800: TH1 = 255;
								break;
		
		case 57600: TH1 = 252;
								PCON = (1 << 8 );
							  break;
		
	}
	
	TR1 = 1; /* start baudrate setting */ 
}


void uart_tx (unsigned char send_data)
{

	SBUF = send_data;
	while (TI == 0);    /* waiting for data transfer */
	//lcd_data(SBUF);
	TI = 0 ; 						/* set TI bit to 0 */
	
}

unsigned char uart_rx(void)
{
	
	while( RI == 0); 	/* waiting for data receve */
	RI = 0;
	
	return SBUF;
}

void uart_tx_string(char *ptr)
{
	while(*ptr != 0)
	{
		SBUF = *ptr;
		while (TI == 0);    /* waiting for data transfer */
		TI = 0 ; 						/* set TI bit to 0 */
		ptr++; 
	}
		
}

void uart_rx_string(char *buf , unsigned char max_length)
{
	unsigned char i;		
	
	for( i = 0; i < max_length; i++)
	{
		while(RI == 0);			/* waiting for data receive */
		RI = 0;
		buf[i] = SBUF;			/* put SBUF data to buf of i */
		
		if(buf[i] == '\r') /* if enter key is press */
		{
			break;					 /* break the loop */
		}
		
	}
	
	buf[i] = 0;      		 /* add null to the end of the string */
	
}




