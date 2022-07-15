/************************* Test cases for tail calls ***************************/
#include <stdio.h>
int TailCallee(int x);
int TailCaller(int x) {
    ++x;
    if (x > 10) {
        return TailCallee(x | 0x21);
    }
    x = TailCallee(x * 10);
    return x + 10;
}

int TailCallee(int x) {
    printf("%d\n", x);
    if (x < 20) return x + 2;
    return x - 2;
}

int TailCallHardCaller(int x);
int TailCallHardCallee(int x) {
    if (x < 30) {
        x *= 49;
        printf("%d\n", x | 0x1000);
        return x + 2;
    } else {
        printf("%d\n", x * 10);
        return TailCallHardCaller(x - 2);
    }

}


int TailCallHardCaller(int x) {
    --x;
    if (x > 10) x = x & 0xffff;
    else x = x | 0x4000;
    return TailCallHardCallee(x * 10);
}


