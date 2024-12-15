#ifndef IO_H
#define IO_H

//header file foe io.c 
//contain enums amd struct for GPIO configration and controlling




//defines
#define SET_BIT(x,y) (x |= (0x1u << y))
#define CLR_BIT(x,y) (x &= ~(0x1u << y))
#define GET_PIN(X) (X & 0x7u)
#define GET_PORT(X) ((X >> 3))
#define UNUSED(X) (void)(X)

// enum

typedef enum{// enum use to select the port pin 
				io_10 = 0,
				io_11,
				io_12,
				io_13,
				io_14,
				io_15,
				io_16,
				io_17,
				io_20,
				io_21,
				io_22,
				io_23,
				io_24,
				io_25,
				io_26,
				io_27,
				io_30,
				io_31,
				io_32,
				io_33,
				io_34,
				io_35,
				io_36,
				io_37,
}io_pin;


typedef enum{// use to check the input pin status
				io_high,
				io_low
}io_status;

typedef enum{// set the direction of port pin used to configure as input 
						 // or output
				io_input,
				io_output
}io_dir;

typedef enum{// use to set the output value when pin configure as output 
				io_set,
				io_clr
}io_put;

typedef enum{// enable the pullup resistor when pin configure as input
				io_pullup_enable,
				io_pullup_disable,
}io_pullup;

typedef enum{// use check the status of operation properly execute 
				io_pullup_error,
				io_pullup_enabled
}io_pullup_status;

typedef enum{
				io_pin_enable,
				io_pin_disable,
}io_pin_enable_e;


struct io_config{// use to write single configuration for pins
				io_dir dir;
				io_put out;
				io_pullup resistor;
};


// functions use in io.h 
// use for configure 
// aslo controll the pin functions

void io_config_pin (io_pin pin, const struct io_config *config);
io_pullup_status io_set_pullup (io_pin pin, io_pullup pullup);
void io_set_dir	(io_pin pin, io_dir dir);
void io_set_pin (io_pin pin,io_put put);
io_status io_get_pin (io_pin pin);


#endif


