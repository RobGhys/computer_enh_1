//
// Created by Robin Ghyselinck on 24/02/2025.
//
#include <cstdint>
#include <iostream>

#include "instruction.h"
#include "bin_str_map.h"

static const BinaryStringMap regMod11W0[] = {
    {0b000, "al"},
    {0b001, "cl"},
    {0b010, "dl"},
    {0b011, "bl"},
    {0b100, "ah"},
    {0b101, "ch"},
    {0b110, "dh"},
    {0b111, "bh"},
};

#define MAPPING_SIZE_W0 (sizeof(regMod11W0) / sizeof(regMod11W0[0]))

const char *binaryToStringW0(uint8_t binary_value) {
    size_t i = 0;
    for (; i < MAPPING_SIZE_W0; i++) {
        if (regMod11W0[i].binary_value == binary_value) {
            return regMod11W0[i].string_value;
        }
    }
    return "err";
}

uint8_t stringToBinaryW0(const char *string_value) {
    size_t i = 0;
    for (; i < MAPPING_SIZE_W0; i++) {
        if (strcmp(regMod11W0[i].string_value, string_value) == 0) {
            return regMod11W0[i].binary_value;
        }
    }
    return 0b00000000;
}

static const BinaryStringMap regMod11W1[] = {
    {0b000, "ax"},
    {0b001, "cx"},
    {0b010, "dx"},
    {0b011, "bx"},
    {0b100, "sp"},
    {0b101, "bp"},
    {0b110, "si"},
    {0b111, "di"},
};

#define MAPPING_SIZE_W1 (sizeof(regMod11W1) / sizeof(regMod11W1[0]))

const char *binaryToStringW1(uint8_t binary_value) {
    size_t i = 0;
    for (i; i < MAPPING_SIZE_W1; i++) {
        if (regMod11W1[i].binary_value == binary_value) {
            return regMod11W1[i].string_value;
        }
    }
    return "err";
}

uint8_t stringToBinaryW1(const char *string_value) {
    size_t i = 0;
    for (i; i < MAPPING_SIZE_W1; i++) {
        if (strcmp(regMod11W1[i].string_value, string_value) == 0) {
            return regMod11W1[i].binary_value;
        }
    }
    return 0b00000000;
}