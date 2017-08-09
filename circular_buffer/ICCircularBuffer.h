#ifndef __CIRCURLAR_BUFFER_H__
#define __CIRCURLAR_BUFFER_H__
#include <stdint.h>

#define ICCircularBufferCreateWithBuffer(data, size) {data, data, data, size}

typedef struct {
    uint8_t *data;
    uint8_t *head;
    uint8_t *tail;
    unsigned int size;
    unsigned int length; //content used
} ICCircularBuffer;

uint8_t ICCircularBufferIsFull(ICCircularBuffer *cb);
void ICCircularBufferAdd(ICCircularBuffer *cb, uint8_t datum);

#endif
