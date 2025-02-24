//
// Created by Robin Ghyselinck on 24/02/2025.
//

#include "bin_str_map.h"

#include <cstdint>
#include <iostream>

static const BinaryStringMap instructMapping[] = {
    {0b100010, "mov"},
    };

#define MAPPING_SIZE (sizeof(instructMapping) / sizeof(instructMapping[0]))

const char *binaryToString(uint8_t binary_value) {
    size_t i = 0;
    for (; i < MAPPING_SIZE; i++) {
        if (instructMapping[i].binary_value == binary_value) {
            return instructMapping[i].string_value;
        }
    }
    return "err";
}

uint8_t stringToBinary(const char *string_value) {
    size_t i = 0;
    for (; i < MAPPING_SIZE; i++) {
        if (strcmp(instructMapping[i].string_value, string_value) == 0) {
            return instructMapping[i].binary_value;
        }
    }
    return 0b00000000;
}