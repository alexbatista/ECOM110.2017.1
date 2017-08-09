#include <stdio.h>
#include <stdint.h>

#define __PACKED __attribute__((__packed__))

typedef uint16_t command_t;

typedef enum {
    A1,
    A2,
    S1,
    S2
} Device;

typedef union {
    uint8_t data[20];
    struct {
        unsigned int enableA1 : 1;
        unsigned int commandA1 : 8;
        unsigned int enableA2 : 1;
        unsigned int commandA2 : 1;
        unsigned int enableS1 : 1;
        unsigned int commandS1 : 8;
        unsigned int enableS2 : 1;
        unsigned int commandS2 : 10;
    } field __PACKED;
} Package;

/*  ToDevice[EnA1(1bit)][CmdA1(8bits)][EnA2(1bit)][CmdA2(1bit)][EnS1(1bit)][CmdS1(8bits)][EnS2(1bit)][CmdS2(10bits)]
 */
void addCommand(Package *pack, Device dev, command_t cmd) {
    switch (dev) {
        case A1:
            pack->field.enableA1 = 1;
            pack->field.commandA1 = cmd;
            break;
        case A2:
            pack->field.enableA2 = 1;
            pack->field.commandA2 = cmd;
           break;
        case S1:
            pack->field.enableS1 = 1;
            pack->field.commandS1 = cmd;
          break;
        case S2:
            pack->field.enableS2 = 1;
            pack->field.commandS2 = cmd;
         break;
    }
}

void decode( Package *pack, uint8_t *raw ) {
    memcpy(pack->data, raw, 20);
}

void printPackage(Package *pack)
{
    if(pack->field.enableA1){
        printf("CommandA1: %x\n", pack->field.commandA1);
    }
    if(pack->field.enableA2){
        printf("CommandA2: %x\n", pack->field.commandA2);
    }
    if(pack->field.enableS1){
        printf("CommandS1: %x\n", pack->field.commandS1);
    }
    if(pack->field.enableS2){
        printf("CommandS2: %x\n", pack->field.commandS2);
    }

}


void main() {
    Package test;
    addCommand(&test, A1, 0b00000111);
    //addCommand(&test, A2, 0b1);
    addCommand(&test, S1, 0x12);
    addCommand(&test, S2, 0x1623);
    printPackage(&test);

    printf("Size of package: %ld\n", sizeof(test.field));
}
