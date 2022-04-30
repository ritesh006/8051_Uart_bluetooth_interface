#include <reg51.h>
#include "header.h"

void main()
{
	unsigned char receive_data;
	
	uart_init(9600);
	lcd_init();
	while(1)
	{
			receive_data = uart_rx();
			uart_tx(receive_data);	
			delay_ms(500);
			lcd_data(receive_data);
		/*	if(receive_data == 'f');
			{
				
				lcd_string("forward");
			} */
			
		
	}
	
	
}