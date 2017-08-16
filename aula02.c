#include <stdio.h>

int main () {

    int d;
    int  var1 = 0;
    d = 0;
    int * c = &var1;
    const char var2[5] = {1,2,3,4,5};
    printf("id=var1, addr=%p, val=%d\n", &var1, var1);
    printf("id=c, addr=%p, val=%p\n", &c, c);
    printf("id=var2, addr=%p, val=%p\n, val=%p", &var2, var2);

    return 0;
}
