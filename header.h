
/* UART function prototype */
extern void uart_init(unsigned int);

extern void uart_tx (unsigned char);

extern unsigned char uart_rx(void);

extern void uart_tx_string(char *);

/* delay funciton prototype */

extern void delay_ms(unsigned int);

/* LCD funcition prototype */

extern void lcd_data(unsigned char);

extern void lcd_cmd(unsigned char );

extern void lcd_init(void);

extern void lcd_string(unsigned char *);

extern void uart_rx_string(char *buf , unsigned char max_length);

