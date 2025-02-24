//
// Created by Robin Ghyselinck on 24/02/2025.
//

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include <cstdint>

typedef struct {
    const char* opCode;
    const char* destination;
    const char* source;
} Instruction;

uint8_t stringToBinaryW1(const char *string_value);
const char *binaryToStringW1(uint8_t binary_value);
uint8_t stringToBinaryW0(const char *string_value);
const char *binaryToStringW0(uint8_t binary_value);

#endif //INSTRUCTION_H
