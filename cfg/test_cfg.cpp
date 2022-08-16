#include <iostream>
using namespace std;

class a_class {
public:
    int number;
    a_class(int n) 
        : number(n) {
        cout << "constructor of a_class\n";
    }
    void mod() {
        ++number;
    }
};

class child_class: public a_class {
public:
    child_class()
        : a_class(1){
        cout << "constructor of child_class\n";
    }
    void mod() {
        --number;
    }
};

void class_access() {
    child_class c = child_class();
    c.mod();
    cout << c.number << "\n";
}

int recursive(int n) {
    if (n==1) {
        return n;
    }
    return recursive(n-1)+n;
}

int loop() {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += i;
    }
    return sum;
}

void my_throw(){
    throw (7);
}
void my_exception() {
    try {
        
        my_throw();
        cout << "never reached\n";
    } catch (int myNum) {
        cout << "catched: " << myNum << "\n";
    }
}

int main() {
    class_access();
    cout << recursive(10) << "\n";
    loop();
    my_exception();
    return 0;
}