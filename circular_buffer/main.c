#include <stdio.h>
#include "circular_buffer.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define CIRCULAR_BUFFER_SIZE 80

int main() {
    uint8_t data[CIRCULAR_BUFFER_SIZE];
    CircularBuffer cb = NEW_CircularBuffer(data, CIRCULAR_BUFFER_SIZE);
    uint8_t randData = 0;
    while(!CircularBuffer_isFull(&cb)) {
        randData = rand();
        CircularBuffer_add(&cb, 1);
        //randData++;
        usleep(50000);
    }
    //int *a = (int *) data;
    for(int i = 0; i < CIRCULAR_BUFFER_SIZE; ++i) {
        printf("%d - %X\n", i, data[i]);
    }
    printf("\n");
    int intData[20];
    memcpy(&intData, (int *)data, 80);
    for(int i = 0; i < 20; ++i) {
        printf("%d - %d\n", i, intData[i]);
    }
    printf("\n");



    return 0;
}
