#include <stdio.h>

#ifdef PACKED_ENABLED
#define PACKED __attribute__((packed))
#else
#define PACKED
#endif


typedef enum {
    false,
    true
} PACKED Boolean;

#define true 1
#define false 0
#define boolean int

void testCond(boolean b) {

}

typedef union {
    short allMasks;
    char masks[2];
    char maskBit0: 1;
    struct {
        char a;
        char b;
    } mask;
    struct {
        unsigned int a0: 1;
        unsigned int a1: 1;
        int a2: 1;
        int a3: 1;
        int a4: 1;
        int a5: 1;
        int a6: 1;
        int a7: 1;
        int a8: 1;
        int a9: 1;
        int a10: 1;
        int a11: 1;
        int a12: 1;
        int a13: 1;
        int a14: 1;
        int a15: 1;
    } PACKED maskBits;
} PACKED Mask;

typedef struct {
    int a;
    char b;

    double c;
} PACKED Weather;


int main() {
    Weather w = {
        .a = 10,
        .b = 'c',
        .c = 5.5
    };

    Mask m;
    m.allMasks = 0x1001;
    printf("%x\n", m.allMasks);
    printf("%x, %x\n", m.masks[1], m.masks[0]);
    printf("%x, %x\n", m.mask.b, m.mask.a);
    printf("%x, %x\n", m.maskBits.a1, m.maskBits.a0);
printf("%ld\n", sizeof(Mask));
    w.a = 1;
    w.b = 'a';// NULL;
    w.c = 2.78;
    printf("Weather a = %d, b = %c, c = %.2f\n %ld\n", w.a, w.b, w.c, sizeof(Weather));
    return 0;
}

