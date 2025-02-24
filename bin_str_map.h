//
// Created by Robin Ghyselinck on 24/02/2025.
//

#ifndef BIN_STR_MAP_H
#define BIN_STR_MAP_H
#include <cstdint>

typedef struct {
    uint8_t binary_value;
    const char* string_value;
} BinaryStringMap;

const char *binaryToString(uint8_t binary_value);
uint8_t stringToBinary(const char *string_value);

#endif //BIN_STR_MAP_H
