#include <stdlib.h>
#include <stdio.h>

/**
 * type: trivial
 * all control flow ended in well-known non-return function
 */
int nonret_trivial_1(int x) {
    if (x < 10) exit(0);
    else exit(-1);
    return 0;
}

/**
 * type: trivial
 * all control flow ended in non-return function
 */
int nonret_trivial_2(int x) {
    if (x < 10) nonret_trivial_1(0);
    else exit(-1);
    return 0;
}


/**
 * type: recurisve
 * two function recurisive call each other
 */
int nonret_recurisve_helper_1(int x);

int nonret_recurisve_helper_2(int x) {
    if (x < 10) nonret_recurisve_helper_1(x + 10);
    else exit(0);
    return 1;
}

int nonret_recurisve_helper_1(int x) {
    if (x > 10) nonret_recurisve_helper_2(x - 10);
    else exit(1);
    return 0;
}

/**
 * type: recurisve
 * two function recurisive call each other
 */
int nonret_recurisve(int x) {
    if (x < 10) {
        nonret_recurisve_helper_1(x + 10);
    } else if (x >= 10 && x < 20) {
        nonret_recurisve_helper_2(x);
    } else {
        nonret_recurisve_helper_1(x - 10);
    }

    return 0;
}

/**
 * type: dataflow analysis
 */
int nonret_dataflow(int x) {
    if (x > 0) {
        exit(0);
    }
    return 0;
}

int main() {
    int x;
    scanf("%d", &x);

    if (x < 1) {
        nonret_trivial_1(x);
    } else if (x < 2) {
        nonret_trivial_2(x);
    } else if (x < 3) {
        nonret_recurisve(x);
    } else if (x < 4) {
        nonret_dataflow(x);
    }
}
