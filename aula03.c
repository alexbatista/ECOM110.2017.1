#include <stdio.h>

void xptr(void **p, void *addr) {
    *p = addr;
}

int main() {
    int m[2][3] = {
        {0,1,2}, 
        {3,4,5}};
    for(int i = 0; i < 3; ++i, printf("\n"))
        for(int j = 0; j < 2; ++j)
            printf("%d,", m[j][i]);
    void *b;
    int e = 100;
    char a[6] = "hello";
    int c = 0xabcdef03;
    b = (void *) &c;
    *((unsigned char*)b + 2) = 0;
    printf("%x\n",*((unsigned char*)b+2));
    printf("%x\n", c);

    printf("%p\n", b);
    xptr(&b, &e);
    printf("%p\n", b);

    if(strcmp(a, b) == 0) {

    }

    return 0;
}

