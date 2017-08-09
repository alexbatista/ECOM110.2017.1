#include "circular_buffer.h"

uint8_t CircularBuffer_isFull(CircularBuffer *cb) {
    return (cb->length == cb->size);
}

void CircularBuffer_add(CircularBuffer *cb, uint8_t datum) {
    if(CircularBuffer_isFull(cb) <= 0) {
        *cb->tail = datum;
        cb->tail++;
        cb->length++;
    }
}

