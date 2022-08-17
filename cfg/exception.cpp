#include <iostream>
#include "throw.h"

using namespace std;

class parent_class {
public:
    int* ptr;
    parent_class(int n) {
        printf("constructor of parent_class\n");
        ptr = new int;
        *ptr = n;
    }
    ~parent_class() {
        printf("destructor of parent_class (%d)\n", *ptr);
        delete ptr;
    }
    void mod() {
        ++(*ptr);
    }
};

class child_class: public parent_class {
public:
    int* another_ptr;
    child_class()
        : parent_class(1){
        printf("constructor of child_class\n");
        another_ptr = new int;
    }
    ~child_class() {
        printf("destructor of child_class (%d %d)\n", *ptr, *another_ptr);
        delete another_ptr;
    }
    void mod() {
        --(*another_ptr);
    }
};

void my_exception() {
    try {
        child_class c = child_class();
        c.mod();
        
        int x;
        int t = scanf("%d", &x);
        if (x % 2) {
            throw_int();
        } else {
            throw_bool();
        }
        
        parent_class p = child_class();
        p.mod();

        printf("never reached\n");

    } catch (int myNum) {
        printf("catched: %d\n", myNum);
    } catch (bool myBool) {
        printf("catched: %s\n", myBool ? "true":"false");
    }
}