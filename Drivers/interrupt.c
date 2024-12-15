#include "avr/interrupt.h"
#include "uart.h"
#include "io.h"
#include "avr/io.h"
#include "interrupt.h"
#include "util/delay.h"

void interr_init(void)
{
	interr_global_enable();
}
void interr_global_enable(void){
	SREG = 0b10000000;
}

ISR(USART_TX_vect){
		uart_tx_callback();
    }

ISR(USART_RX_vect){
		uart_rx_callback();
    }
