#include <stdio.h>

int main() {
    int i = 5;
    int a = 10;
    a = i++;
    printf("%d", a);
    int x = 0;
aqui:
    printf("x = %d\n", ++x);
    if(x < 10) goto aqui;
}

