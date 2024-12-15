//
//
//
//
//
//              file name : io.c
//
//driver file use to configure the atmega328 controller
//          GPIO and controll the port pins
//
//
//write by Suresh kumar.v
//



#include "io.h"
#include "avr/io.h"


//below set of array use to carry the register address value for easy accessing 
//and made this array as static avoid conflict with other files
//also make it volatile avoid compiler optimitation
//below three register 
//-direction 
//-data
//-input
static volatile uint8_t *const port_dir_regs[3] = { &DDRB, &DDRC, &DDRD};
static volatile uint8_t *const port_data_regs[3] = { &PORTB, &PORTC, &PORTD};
static volatile uint8_t *const port_pin_regs[3] = { &PINB, &PINC, &PIND};



//below function is use to configure the specfic pin
//function takes configure struture and pin number to
//config the particular pin
// use for easy configuration 
// also configure multiple pins
void io_config_pin (io_pin pin, const struct io_config *config)
{
				io_set_dir(pin, config->dir);
				if (config->dir == io_input)
				{
							 io_set_pullup(pin, config->resistor);				
				}
				else if (config->dir == io_output)
				{
							 io_set_pin(pin, config->out);
				}
}


//below function is use to set the pin pullup resistor
//function takes pin number and resistor enable or disable value
//use to configure pullup resistor
//and also return the status as return 
//controller use same register for data and pullup
//so if any pin configure the pin direction as output 
//return the error msg 
io_pullup_status io_set_pullup (io_pin pin, io_pullup pullup)
{
				uint8_t ppin = GET_PIN(pin);
				uint8_t pport = GET_PORT(pin);

				if ((*port_dir_regs[pport] & (0x1u << ppin)) != 0)
				{
								return io_pullup_error;
				}
				else if (pullup == io_pullup_enable)
				{
								SET_BIT(*port_data_regs[pport], ppin);
				}
				else if (pullup == io_pullup_disable)
				{
								CLR_BIT(*port_data_regs[pport], ppin);
				}
				else
				{
								//nothing
				}

				return io_pullup_enabled;
}


//function use to set the direction of pin
//function takes arugument as pin number and direction 
//input or output 
void io_set_dir	(io_pin pin, io_dir dir)
{
				uint8_t ppin = GET_PIN(pin);
				uint8_t pport = GET_PORT(pin);
				
				if (dir == io_output)
				{
 								SET_BIT(*port_dir_regs[pport], ppin);
		
				}
				else if (dir == io_input)
				{
								CLR_BIT(*port_dir_regs[pport], ppin);
				}
				else
				{
				// nothing
				}
				
}


//function use to set the pin as high or low
//function takes pin number and pin valur as arugument
//function use when pin configure as output
void io_set_pin (io_pin pin, io_put put)
{
				uint8_t ppin = GET_PIN(pin);
				uint8_t pport = GET_PORT(pin);
				
				if (put == io_set)
				{
								SET_BIT(*port_data_regs[pport], ppin);
				}
				else if (put == io_clr)
				{
								CLR_BIT(*port_data_regs[pport], ppin);
				}
				else
				{
								//nothing
				}
				
				
}


// below funtion is use to set
// the gpio high or low
// get pin number as a input and 
// get the port and pin data and set the io
io_status io_get_pin (io_pin pin)
{
				uint8_t ppin = GET_PIN(pin);
				uint8_t pport = GET_PORT(pin);

				if ((*port_pin_regs[pport] & (0x1u << ppin)) == 0)
				{
								return io_low;
				}
				else
				{
								return io_high;
				}

}

//file end
