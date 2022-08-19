#include <iostream>
#include "throw.h"

using namespace std;

class parent_class {
public:
    int* ptr;
    parent_class() {
        printf("constructor of parent_class\n");
        ptr = new int;
        *ptr = 10;
    }
    ~parent_class() {
        printf("destructor of parent_class (%d)\n", *ptr);
        delete ptr;
    }
    void modify() {
        ++(*ptr);
    }
};

class child_class: public parent_class {
public:
    int* another_ptr;
    child_class()
        : parent_class(){
        printf("constructor of child_class\n");
        another_ptr = new int;
        *another_ptr = 10;
    }
    ~child_class() {
        printf("destructor of child_class (%d, %d)\n", *ptr, *another_ptr);
        delete another_ptr;
    }
    void modify() {
        --(*ptr);
        ++(*another_ptr);
    }
};

void my_exception_easy() {
    try {
        child_class c = child_class();
        c.modify();
        throw_int();
    } catch (int myNum) {
        printf("catched: %d\n", myNum);
    }
}

void my_exception_nested() {
    try {
        parent_class p = parent_class();
        p.modify();
        
        throw_bool();
        
        child_class c = child_class();
        c.modify();
    } catch (int myNum) {
        printf("catched: %d\n", myNum);
    } catch (bool myBool) {
        printf("catched: %s\n", myBool ? "true":"false");
    }
}