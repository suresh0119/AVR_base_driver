#include "uart.h"
#include "ring_buf.h"
#include "io.h"
#include "avr/io.h"
#include "util/delay.h"


//NEED TO DO
//frame error
//data overrun
//parrity error
//

#define SET_BIT(x,y) (x |= (0x1u << y))
#define CLR_BIT(x,y) (x &= ~(0x1u << y))
#define CHECK_BIT(x,y) (x & (0x1u << y))
#define GET_PIN(X) (X & 0x7u)
#define GET_PORT(X) ((X >> 3))
#define UNUSED(X) (void)(X)



#define FOSC 16000000

uart_error_e uart_config(const struct uart_config_struct *u_config)
{
				if(u_config->bard_rate == no_config || u_config->tx == no_config || \
					 u_config->rx == no_config || u_config->data_len == no_config || \
					 u_config->parity == no_config || u_config->stop_bit == no_config || \
					 u_config->trans_speed == no_config || u_config->multi_mode == no_config || \
					 u_config->op_mode == no_config || u_config->tx_interrupt == no_config || \
					 u_config->rx_interrupt == no_config )
				{
								return uart_config_error;
				}
				else
				{
								uint16_t b_rate = FOSC/16/u_config->bard_rate - 1;
								UBRR0H = (uint8_t)(b_rate >> 8);
								UBRR0L = (uint8_t)(b_rate);

								if (u_config->tx == transmitter_enable)
								{
												SET_BIT(UCSR0B,3);
								}
								else if (u_config->tx == transmitter_disabe)
								{
												CLR_BIT(UCSR0B,3);
								}

								if (u_config->rx == receiver_enable)
								{
												SET_BIT(UCSR0B,4);
								}
								else if (u_config->rx == receiver_disable)
								{
												CLR_BIT(UCSR0B,4);
								}

								if (u_config->data_len == _5_bit_data)
								{
												CLR_BIT(UCSR0B,2);
												CLR_BIT(UCSR0C,2);
												CLR_BIT(UCSR0C,1);
								}
								else if (u_config->data_len == _6_bit_data)
								{
												CLR_BIT(UCSR0B,2);
												CLR_BIT(UCSR0C,2);
												SET_BIT(UCSR0C,1);
								}
								else if (u_config->data_len == _7_bit_data)
								{
												CLR_BIT(UCSR0B,2);
												SET_BIT(UCSR0C,2);
												CLR_BIT(UCSR0C,1);
								}
								else if (u_config->data_len == _8_bit_data)
								{
												CLR_BIT(UCSR0B,2);
												SET_BIT(UCSR0C,2);
												SET_BIT(UCSR0C,1);
								}
								else if (u_config->data_len == _9_bit_data)
								{
												SET_BIT(UCSR0B,2);
												SET_BIT(UCSR0C,2);
												SET_BIT(UCSR0C,1);
								}


								if (u_config->parity == odd_parity)
								{
												CLR_BIT(UCSR0C,4);
												SET_BIT(UCSR0C,5);
								}
								else if (u_config->parity == even_parity)
								{
												SET_BIT(UCSR0C,4);
												SET_BIT(UCSR0C,5);
								}


								if (u_config->stop_bit == stop_1_bit)
								{
												CLR_BIT(UCSR0C,3);
								}
								else if (u_config->stop_bit == stop_2bit)
								{
												SET_BIT(UCSR0C,3);
								}

								if (u_config->trans_speed == single_transmission_speed)
								{
												CLR_BIT(UCSR0A,1);
								}
								else if (u_config->trans_speed == double_transmission_speed)
								{
												SET_BIT(UCSR0A,1);
								}

								if (u_config->multi_mode == non_multi_mode)
								{
												CLR_BIT(UCSR0A,0);
								}
								else if (u_config->multi_mode == multi_mode)
								{
												SET_BIT(UCSR0A,0);
								}

								if (u_config->op_mode == asynchronous)
								{
												CLR_BIT(UCSR0C,6);
												CLR_BIT(UCSR0C,7);
								}
								else if (u_config->op_mode == synchronous)
								{
												SET_BIT(UCSR0C,6);
                        CLR_BIT(UCSR0C,7);
								}
								else if (u_config->op_mode == master_SPI)
								{
												SET_BIT(UCSR0C,6);
                        SET_BIT(UCSR0C,7);
								}

								if (u_config->tx_interrupt == tx_intrr_enable)
								{
												SET_BIT(UCSR0B,6);
								}
								else if (u_config->tx_interrupt == tx_intrr_disable)
								{
												CLR_BIT(UCSR0B,6);
								}


								if (u_config->rx_interrupt == rx_intrr_enable)
								{
												SET_BIT(UCSR0B,7);
								}
								else if (u_config->rx_interrupt == rx_intrr_disable)
								{
												CLR_BIT(UCSR0B,7);
								}



								return uart_config_sucess;
				}
}




void uart_transmit(uint8_t data)
{
				while(!(UCSR0A & (1<<5)));

				UDR0 = data;
}

void uart_transmit_9bit(uint16_t data)
{
				while(!(UCSR0A & (1<<5)));

				CLR_BIT(UCSR0B,0);

				if(data & (uint16_t)0x100)
				{
								SET_BIT(UCSR0B,0);
				}

				UDR0 = (uint8_t)data;
}


void uart_tx_callback(void)
{
	uint8_t tmp;
	if (ring_get_size(&tx_ring)){
		ring_get_char(&tx_ring, &tmp);
		if (tmp != '!'){
			uart_transmit(tmp);
		}
		// uart_transmit(tx_ring.size + 48);
		// uart_transmit('\n');
	}
}

void uart_reciver(uint8_t *data)
{
				while(!(UCSR0A & (1<<7)));

				*data = UDR0;
}
void uart_reciver_9bit(uint16_t *data)
{
				while(!(UCSR0A & (1<<7)));

				*data = UDR0;

				if (UCSR0B & (1<<0))
				{
								*data += (uint16_t)0x100;

				}


}


void uart_rx_callback(void){

	ring_put_char(&rx_ring,(uint8_t)UDR0);
}
