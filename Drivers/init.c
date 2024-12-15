#include "init.h"
#include "io.h"
#include "uart.h"
#include "interrupt.h"

#define  PORT_TABLE_SIZE 20


struct port_table_s{
    io_pin pin;
    const struct io_config config;
    io_pin_enable_e enable;
};

const struct port_table_s port_look_table[PORT_TABLE_SIZE] = {


    //io_16 - clock
	//io_17 - clock
    //io_26 - reset
	//io_27 - invile}d
            {io_10,   {  io_output,   io_set,     io_pullup_disable},     io_pin_enable},
			{io_11,   {  io_output,   io_set,     io_pullup_disable},     io_pin_enable},
			{io_12,   {  io_output,   io_set,     io_pullup_disable},     io_pin_enable},
			{io_13,   {  io_input,    io_set,     io_pullup_enable},      io_pin_disable},
			{io_14,   {  io_output,   io_set,     io_pullup_disable},     io_pin_enable},
			{io_15,   {  io_output,   io_clr,     io_pullup_disable},     io_pin_enable},
			{io_20,   {  io_input,    io_set,     io_pullup_enable},      io_pin_enable},
			{io_21,   {  io_output,   io_set,     io_pullup_disable},     io_pin_enable},
			{io_22,   {  io_output,   io_set,     io_pullup_disable},     io_pin_enable},
			{io_23,   {  io_input,    io_set,     io_pullup_enable},      io_pin_disable},
			{io_24,   {  io_input,    io_set,     io_pullup_enable},      io_pin_disable},
            {io_25,   {  io_input,    io_set,     io_pullup_enable},      io_pin_disable},
            {io_30,   {  io_input,    io_set,     io_pullup_enable},      io_pin_enable},
            {io_31,   {  io_input,    io_set,     io_pullup_enable},      io_pin_enable},
            {io_32,   {  io_input,    io_set,     io_pullup_enable},      io_pin_enable},
            {io_33,   {  io_input,    io_set,     io_pullup_enable},      io_pin_disable},
            {io_34,   {  io_input,    io_set,     io_pullup_enable},      io_pin_enable},
            {io_35,   {  io_input,    io_set,     io_pullup_enable},      io_pin_enable},
            {io_36,   {  io_input,    io_set,     io_pullup_enable},      io_pin_enable},
            {io_37,   {  io_input,    io_set,     io_pullup_enable},      io_pin_enable}
};

static void init_port_config(void);
static void init_uart_config(void);

void init_mcu(void){
    init_port_config();
    init_uart_config();
    interr_init();
    uart_transmit('-');
}


static void init_port_config(void){
    {
        unsigned char index;

        for (index = 0; index < PORT_TABLE_SIZE; index++)
        {
            io_config_pin
            (
                port_look_table[index].pin,
                &port_look_table[index].config
            );
        }
    }
}

static void init_uart_config(void){
    {
				const struct uart_config_struct new_u_config = {
								.bard_rate =19200,
								.tx = transmitter_enable,
								.rx = receiver_enable,
								.data_len = _8_bit_data,
								.parity = no_parity,
								.stop_bit = stop_1_bit,
								.trans_speed = single_transmission_speed,
								.multi_mode = non_multi_mode,
								.op_mode = asynchronous,
								.tx_interrupt = tx_intrr_disable,
								.rx_interrupt = rx_intrr_disable,
				};
    }
}


