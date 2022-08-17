#include <iostream>
#include "exception.h"

using namespace std;

int recursive(int n) {
    if (n==1) {
        return n;
    }
    return recursive(n-1)+n;
}

int loop() {
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

int main() {
    cout << recursive(10) << "\n";
    loop();
    my_exception();
    return 0;
}