#ifndef RING_BUF_H
#define RING_BUF_H

#include "avr/io.h"

#define BUFFER_SIZE 100

struct ring
{
				uint8_t array[BUFFER_SIZE];
				uint8_t w_index;
				uint8_t r_index;
				uint8_t size;
				uint8_t total;
};


extern struct ring tx_ring;
extern struct ring rx_ring;

void ring_buf_init(void);
uint8_t ring_get_size(struct ring *rb);
void ring_put_char(struct ring *rb, uint8_t data);
void ring_get_char(struct ring *rb, uint8_t *data);
void ring_send_string(struct ring *rb, uint8_t *data, uint8_t end);
uint8_t *ring_get_string(struct ring *rb, uint8_t end);
uint8_t *ring_get_all_string(struct ring *rb);

#endif
