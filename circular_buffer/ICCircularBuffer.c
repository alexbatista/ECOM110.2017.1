#include "ICCircularBuffer.h"

uint8_t ICCircularBufferIsFull(ICCircularBuffer *cb) {
    return (cb->length == cb->size);
}

void ICCircularBufferAdd(ICCircularBuffer *cb, uint8_t datum) {
    if(ICCircularBufferIsFull(cb) <= 0) {
        *cb->tail = datum;
        cb->tail++;
        cb->length++;
    }
}

