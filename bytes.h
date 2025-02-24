//
// Created by Robin Ghyselinck on 24/02/2025.
//

#ifndef BYTES_H
#define BYTES_H
#include <cstdint>


typedef struct {
    // e.g. mov
    const char* opCode;
    // 0: to register | 1: from register
    bool direction;
    // 0: 8 bits | 1: 16 bits
    bool wordOp;
} Byte1;

typedef struct {
    // 2bits
    uint8_t mod;
    // 3 bits
    uint8_t reg;
    // 3 bits
    uint8_t rm;
} Byte2;


Byte1 *getByte1(unsigned char byte, bool debug);
Byte2 *getByte2(unsigned char byte, bool debug);
void print1Byte(uint8_t byte);
void printPartOf1Byte(uint8_t byte, int nbBitsToRead);

#endif //BYTES_H
