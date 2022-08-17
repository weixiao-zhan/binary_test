#include <exception>

int throw_int() {
    throw(7);
}

int throw_bool() {
    throw(false);
}

int throw_exception() {
    throw(new std::exception());
}