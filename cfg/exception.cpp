#include <iostream>
#include "throw.h"

using namespace std;

class simple_exception {
public:
    simple_exception();
    ~simple_exception();
};
simple_exception::simple_exception() {}
simple_exception::~simple_exception() {}

class parent_class {
public:
    int* ptr;
    parent_class();
    ~parent_class();
    void modify();
};
parent_class::parent_class() {
    printf("constructor of parent_class\n");
    ptr = new int;
    *ptr = 10;
}
parent_class::~parent_class() {
    printf("destructor of parent_class (%d)\n", *ptr);
    delete ptr;
}
void parent_class::modify() {
    ++(*ptr);
}

class child_class: public parent_class {
public:
    int* another_ptr;
    child_class();
    ~child_class();
    void modify();
};
child_class::child_class()
    : parent_class(){
    printf("constructor of child_class\n");
    another_ptr = new int;
    *another_ptr = 10;
}
child_class::~child_class() {
    printf("destructor of child_class (%d, %d)\n", *ptr, *another_ptr);
    delete another_ptr;
}
void child_class::modify() {
    parent_class::modify();
    ++(*another_ptr);
}

void my_exception_1() {
    try {
        throw(simple_exception());
    } catch (simple_exception& e) {
        printf("catched");
    }
}

void my_exception_2() {
    try {
        child_class c = child_class();
        c.modify();
        throw_int();
    } catch (int myNum) {
        printf("catched: %d\n", myNum);
    }
}

void my_exception_3() {
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

void std_exception() {
    try{
        int* tmp = new int;
        *(tmp + 32768) = 1;
        delete tmp;
    } catch (std::exception& e) {
        printf("catched: %s\n", e.what());
    }
}