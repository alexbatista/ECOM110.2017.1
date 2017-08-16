#include <stdio.h>

typedef void (*Function)(Device * dev);

int func(int a, int b) {
    return a + b;
}

typedef struct {
    int val,
    int val2
} Device;

Device initDevice(int val, int val2) {
    Device d;
    d.val = val;
    d.val2 = val2;
    return d;
}

void BQDeviceInitWithData(Device *d, int val, int val2) {
    d->val = val;
    d->val2 = val2;
    return d;
}

#define initDevice(val, val2) {val, val2}
main() {
    Device d; 8b
    initDevice(&d, 10, 20); //24

    Device d = initDevice(10, 20); //24
    Device d = {10, 20} //24

}

/*typedef struct {
    Function open;
    Function close;
    read
    write
    ioctl
} Driver;
*/
/*
void func(const int *value) const {
    value = &value2;
}*/

int main() {
    /*int x = 10;
    int y = 100;
    const int * a = &x;
    int const * b = &x;

    int const * const c = &x;
    c = &y;
    *c = 150;
    */
    IntFunction *soma;
    soma = func;
    printf("%d\n",(*soma)(10, 50));
    return 0;
}
