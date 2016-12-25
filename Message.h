#pragma once
#include <iostream>

struct Message {
};

struct Data {
    int size;
    char * data;

    ~Data() {
        delete[] data;
    }
};