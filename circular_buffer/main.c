#include <stdio.h>
#include "ICCircularBuffer.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define CIRCULAR_BUFFER_SIZE 80

int main() {
    uint8_t data[CIRCULAR_BUFFER_SIZE];
    ICCircularBuffer cb = ICCircularBufferCreateWithBuffer(data, CIRCULAR_BUFFER_SIZE);
    uint8_t randData = 0;
    while(!ICCircularBufferIsFull(&cb)) {
        randData = rand();
        ICCircularBufferAdd(&cb, 1);
        usleep(50000);
	printf(".");
    }
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
