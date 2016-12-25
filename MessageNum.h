//
// Created by aleksey on 25.12.16.
//

#ifndef SOCKETLIB_MESSAGENUM_H
#define SOCKETLIB_MESSAGENUM_H


struct MessageNum : Message {
    MessageNum(int num = 15) : number(num) {}
    int number;
};


#endif //SOCKETLIB_MESSAGENUM_H
