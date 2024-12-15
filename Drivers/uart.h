#ifndef UART_H
#define UART_H

#include "avr/io.h"


#define E_config 1
#define no_config 0

typedef enum
{
				uart_config_sucess,
				uart_config_error
}
uart_error_e;


typedef enum
{
				receiver_enable = E_config,
				receiver_disable,
				transmitter_enable,
				transmitter_disabe,
}
uart_tx_rx_config_e;

typedef enum
{
				_5_bit_data = E_config,
				_6_bit_data,
				_7_bit_data,
				_8_bit_data,
				_9_bit_data,
}
uart_data_len_e;

typedef enum
{
				no_parity = E_config,
				odd_parity,
				even_parity,
}
uart_parity_e;

typedef enum
{
				stop_1_bit = E_config,
				stop_2bit,
}
uart_stop_bit_e;

typedef enum
{
				single_transmission_speed = E_config,
				double_transmission_speed,
}
uart_transmission_speed_e;

typedef enum
{
				non_multi_mode = E_config,
				multi_mode,
}
uart_multi_mode_e;

typedef enum
{
				asynchronous = E_config,
				synchronous,
				master_SPI
}
uart_operation_mode_e;

typedef enum
{
				tx_intrr_enable = E_config,
				tx_intrr_disable,
				rx_intrr_enable,
				rx_intrr_disable,
}
uart_inter_e;

struct uart_config_struct
{
				uint16_t bard_rate;
				uart_tx_rx_config_e tx;
			 	uart_tx_rx_config_e rx;
				uart_data_len_e data_len;
				uart_parity_e parity;
				uart_stop_bit_e stop_bit;
				uart_transmission_speed_e trans_speed;
				uart_multi_mode_e multi_mode;
				uart_operation_mode_e op_mode;
				uart_inter_e tx_interrupt;
				uart_inter_e rx_interrupt;
};

uart_error_e uart_config(const struct uart_config_struct *u_config);
void uart_transmit(uint8_t data);
void uart_transmit_9bit(uint16_t data);
void uart_tx_callback(void);
void uart_reciver(uint8_t *data);
void uart_reciver_9bit(uint16_t *data);
void uart_rx_callback(void);

#endif
