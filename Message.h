#pragma once
#include <iostream>

struct Message {
    virtual size_t size() const
    {
        return sizeof(*this);
    }

    virtual std::string to_str(){
        return "";
    }
};

struct Data {
    int size;
    char * data;

    ~Data() {
        delete[] data;
    }
};