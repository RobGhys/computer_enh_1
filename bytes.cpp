//
// Created by Robin Ghyselinck on 24/02/2025.
//

#include "bytes.h"

#include <cstdio>
#include <cstdlib>

#include "bin_str_map.h"

Byte1 *getByte1(unsigned char byte) {
    Byte1 *byte1 = (Byte1 *)malloc(sizeof(Byte1));

    if (byte1 == NULL) {
        return NULL;
    }
    // check the first 6 bytes : 100010
    const char *movOpCode = binaryToString(byte >> 2);
    byte1->opCode = movOpCode;
    printf("%s |", byte1->opCode);

    // 7th
    byte1->direction = (byte >> 1) & 1;
    printf("D=%hhd |", byte1->direction);

    // 8th
    byte1->wordOp = byte & 1;
    printf("W=%hhd\n", byte1->wordOp);

    return byte1;
}

Byte2 *getByte2(unsigned char byte) {
    Byte2 *byte2 = (Byte2 *)malloc(sizeof(Byte2));

    if (byte2 == NULL) {
        return NULL;
    }
    byte2->mod = byte >> 6;
    printf("MOD=");
    printPartOf1Byte(byte2->mod, 2);
    printf("|");

    int8_t mask = 0b111;
    // offset 3 bits (there are 5 remaining), read 3 last bits
    byte2->reg = (byte >> 3) & mask;
    printf("REG=");
    printPartOf1Byte(byte2->reg, 3);
    printf("|");

    // just read the 3 last bits
    byte2->rm = byte & mask;
    printf("RM=");
    printPartOf1Byte(byte2->rm, 3);

    return byte2;
}

void print1Byte(uint8_t byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
    printf(" ");
}

void printPartOf1Byte(uint8_t byte, int nbBitsToRead) {
    int i = nbBitsToRead - 1;
    for (; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
    printf(" ");
}