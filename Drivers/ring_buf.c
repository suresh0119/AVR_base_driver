#include "ring_buf.h"
#include <stddef.h>



struct ring tx_ring = {{'\0'}, 0, 0, 0, BUFFER_SIZE};
struct ring rx_ring = {{'\0'}, 0, 0, 0, BUFFER_SIZE};




uint8_t ring_get_size(struct ring *rb){
				if ((rb->w_index) == (rb->r_index))
						return 0;
				else if ((rb->w_index) > (rb->r_index))
						return ((rb->w_index) - rb->r_index);
				else
						return (rb->total - rb->r_index) + (rb->w_index);
}


void ring_get_char(struct ring *rb, uint8_t *data){
        if (rb->size){
				char tmp;
				tmp = rb->array[rb->r_index];
				rb->r_index++;
				rb->size = ring_get_size(rb);
				*data = tmp;
            }
}

void ring_put_char(struct ring *rb, uint8_t data){
				rb->array[rb->w_index] = data;
				rb->w_index++;

				if (rb->w_index == BUFFER_SIZE){
							rb->w_index = 0;
				}
				rb->size = ring_get_size(rb);

}

void ring_send_string(struct ring *rb, uint8_t *data, uint8_t end){
    while (*data != end){
        ring_put_char(rb, *data);
        data++;
    }
}

uint8_t *ring_get_string(struct ring *rb, uint8_t end){
    uint8_t tmp;
    uint8_t *data = NULL;
    while (1){
        ring_get_char(rb, &tmp);
        if (tmp == end){
            return (uint8_t*)data;
        }
        else{
            *data = tmp;
            data++;
        }
    }
    return (uint8_t*)data;
}

uint8_t *ring_get_all_string(struct ring *rb){
    uint8_t tmp;
    uint8_t *data = NULL;
    while (ring_get_size(rb)){
        ring_get_char(rb, &tmp);
            *data = tmp;
            data++;
    }
    return (uint8_t*)data;
}
