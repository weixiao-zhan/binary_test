#include <stdlib.h>
#include <stdio.h>

/**
 * type: trivial
 * all control flow ended in well-known non-return function
 */
int nonret_trivial_1(int x) {
    if (x < 10) {
        exit(0);
    } else {
        exit(-1);
        printf("never reached");
    }

    return 0;
}

/**
 * type: trivial
 * all control flow ended in non-return function
 */
int nonret_trivial_2(int x) {
    if (x < 10) {
        nonret_trivial_1(0);
        printf("never reached");
    } else {
        exit(-1);
    }
    
    return 0;
}

/**
 * type: trivial
 * all control flow ended in non-return function
 */
int nonret_trivial_3(int x) {
    if (x < 10) {
        nonret_trivial_2(0);
        printf("never reached");
    } else {
        exit(-1);
    }
    
    return 0;
}

int nonret_recurisve_helper_1(int x);
int nonret_recurisve_helper_2(int x);
int nonret_recurisve_helper_3(int x);

int nonret_recurisve_helper_1(int x) {
    if (x > 10) {
        nonret_recurisve_helper_2(x - 10);
        printf("never reached");
    } else {
        nonret_recurisve_helper_3(x);
        printf("never reached");
    }
    return 0;
}
int nonret_recurisve_helper_2(int x) {
    if (x > 10) {
        nonret_recurisve_helper_3(x - 10);
        printf("never reached");
    } else {
        nonret_recurisve_helper_1(x);
        printf("never reached");
    }
    return 0;
}
int nonret_recurisve_helper_3(int x) {
    if (x > 10) {
        nonret_recurisve_helper_1(x - 10);
        printf("never reached");
    } else {
        nonret_recurisve_helper_2(x);
        printf("never reached");
    }
    return 0;
}

/**
 * type: recurisve
 * two function recursive call each other
 */
int nonret_recurisve(int x) {
    if (x < 10) {
        nonret_recurisve_helper_1(x + 10);
    } else if (x >= 10 && x < 20) {
        nonret_recurisve_helper_2(x);
    } else {
        nonret_recurisve_helper_3(x - 10);
    }

    return 0;
}

/**
 * type: dataflow analysis
 */
int __attribute__((optimize("Og"))) nonret_dataflow_callee(int x) {
    if (x <= 0) {
        exit(0);
    }
    return x;
}

int ret_dataflow(int x) {
    return nonret_dataflow_callee(x);
}

int nonret_dataflow(int x) {
    if (x <= 0) {
        x = nonret_dataflow_callee(x);
    } else {
        x = nonret_dataflow_callee(x * -1);
    }
    printf("never reached");
    return x;
}

int x;

int main() {
    int n = scanf("%d", &x);
    
    nonret_dataflow(x);
    printf("never reached");
    
    if (x < 1) {
        nonret_trivial_1(x);
    } else if (x < 2) {
        nonret_trivial_2(x);
    } else if (x < 3) {
        nonret_trivial_3(x);
    } else {
        nonret_recurisve(x);
    }

    printf("never reached");
}
