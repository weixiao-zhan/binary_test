/************ Test cases for non returning functions **********************************/

#include <stdlib.h>

/************ The easy test case ******************************/
int NonReturnCallTestEasy(int x) {
    if (x < 10) exit(0);
    else exit(-1);
    return 0;
}

/************ The hard test case  ******************************/
int NonReturnCall1(int x);

int NonReturnCall2(int x) {
    if (x < 10) NonReturnCall1(x + 10);
    else exit(0);
    return 1;
}

int NonReturnCall1(int x) {
    if (x > 10) NonReturnCall2(x - 10);
    else exit(1);
    return 0;
}

int NonReturnCallTestHard(int x) {

    if (x < 10) NonReturnCall1(x + 10);
    else if (x >= 10 && x < 20) NonReturnCall2(x);
    else NonReturnCall1(x - 10);
    return 0;
}


