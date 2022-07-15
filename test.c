#include <stdio.h>

#include "test.h"

int main() {
    int x,y;
    scanf("%d %d", &x, &y);
    
    DataInText(x);
    
    SwitchStatement(x,y);

    TailCaller(x);
    TailCallHardCaller(y);

    if (x < 10) NonReturnCallTestEasy(x);
    if (x > 100) NonReturnCallTestHard(x);
}
