#pragma once
struct Message {

};

struct Data {
    int size;
    char * data;

    ~Data() {
        delete[] data;
    }
};