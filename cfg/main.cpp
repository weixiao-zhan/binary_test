#include <iostream>
#include "exception.h"

using namespace std;

int recursive(int n) {
    if (n==1) {
        return n;
    }
    return recursive(n-1)+n;
}

int loop_nested() {
    int num[10][10];
    int sum;
    for (int x = 0; x < 10; x++){
        for (int y = 0; y < 10; y++){
            num[x][y] = x*10+y;
        }
        for (int z = 0; z < 10; z++){
            num[x][z] = num[x][z] + z + x;
        }
    }
    for (int i = 0; i < 10; i++){
        sum += num[i][i];
    }
    return sum;
}

void loop_irreducible(){
    int x,y;
    scanf("%d %d",&x, &y);
    if (x+y > 10) {
        while (x + y < 100) {
            x = x + y;
            L: y = y + x / 2;
	    }
    } else {
        goto L;
    }

    printf("%d %d\n",x ,y);
}

/**
 * jump to inner loop from outside of the nested loops
*/
void loop_mixed_1() {
    int x, y, n;
    scanf("%d %d %d",&x, &y, &n);
    int num[n][n];

    int i = 0, j = 0;
    for (; i < n; ++i){
        for (; j > 0; --j){
            L1: num[i][j] = x*10+y;
        }
    }
    if (n > 10){
        goto L1;
    }
}

/**
 * jump to an inner loop from the outer loop
*/
void loop_mixed_2() {
    int x, y, n;
    scanf("%d %d %d",&x, &y, &n);
    int num[n][n];
    int i = 0, j = 0;
    for (; i < n; ++i){
        for (; j > 0; --j){
            L2: num[i][j] = x*10+y;
        }
        if (n > 10){
            goto L2;
        }
    }
}


/**
 * jump to a loop from another loop
*/
void loop_mixed_3() {
    int x, y, n;
    scanf("%d %d %d",&x, &y, &n);
    int num[n][n];
    int i = 0, j = 0;
    for (; i < n; ++i){
        for (; j > 0; --j){
            L3: num[i][j] = x*10+y;
        }
    }

    for (int k = 0; k < n; k++){
        if (k>20) {
            goto L3;
        }
    }
}


int main() {
    cout << recursive(10) << "\n";
    loop_nested();
    loop_irreducible();
    loop_mixed_1();
    loop_mixed_2();
    loop_mixed_3();
    
    my_exception_1();
    my_exception_2();
    my_exception_3();
    std_exception();
    return 0;
}