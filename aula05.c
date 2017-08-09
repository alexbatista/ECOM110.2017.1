#include <stdio.h>

#define FSM
#define STATE(st) s_##st:
#define NEXT_STATE(st) goto s_##st
#define FINAL_STATE(st) STATE(st)
#define START_AT(st) NEXT_STATE(st)

int main () {
    int count = 0;
    int a = 1;
    FSM {
        START_AT(init);
        STATE(check) {
            int a = 10;
            printf("check, %d\n", a);
            NEXT_STATE(exec);
        }
        STATE(init) {
            printf("init\n");
            NEXT_STATE(check);
        }
        STATE(exec) {
            a++;
            printf("exec %d, %d\n", a, count);
            if(count < 10) {
                count++;
                NEXT_STATE(init);
            } else {
                NEXT_STATE(end);
            }
        }
        FINAL_STATE(end) {
            printf("end!\n");
        }
    }
    printf("The end!");
    return 0;
}
