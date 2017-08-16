#ifndef __CIRCURLAR_BUFFER_H__
#define __CIRCURLAR_BUFFER_H__
#include <stdint.h>

#define NEW_CircularBuffer(data, size) {data, data, data, size}

typedef struct {
    uint8_t *data;
    uint8_t *head;
    uint8_t *tail;
    unsigned int size;
    unsigned int length; //content used
} CircularBuffer;

uint8_t CircularBuffer_isFull(CircularBuffer *cb);
void CircularBuffer_add(CircularBuffer *cb, uint8_t datum);

#endif
