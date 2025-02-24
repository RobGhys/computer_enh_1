#include <iostream>
#include <stdlib.h>
#include <stdint.h>

#include "bytes.h"
#include "instruction.h"

#define BYTES_PER_READ 1
#define BYTE_SIZE 1

// 10001001 11011001


/*const char *decodeOp(unsigned char byte) {
    // check the first 6 bytes : 100010
    uint8_t mask = 0b11111100;
    const char *movOpCode = binaryToString((byte & mask) >> 2);

    printf("%s", movOpCode);
    return movOpCode;
}*/

int main(int argc, char *argv[]) {
    size_t byte_nb = BYTES_PER_READ;
    size_t byte_size = BYTE_SIZE;
    FILE *fptr;
    bool debug = false;

    if(argc < 2 || argc > 3) {
        printf("Usage: %s <file_name> [debug]\n", argv[0]);
        printf("       debug: 1 to activate debug mode, 0 or nothing to deactivate it\n");
        exit(1);
    }

    if (argc == 3) {
        debug = (atoi(argv[2]) == 1);
    }

    if (debug) {
        printf("Debug is ON.");
    } else {
        printf("Debug is OFF.");
    }

    fptr = fopen(argv[1], "rb");

    if (fptr == NULL) {
        printf("File not open. Exiting the program...");
        exit(0);
    }

    printf("Read file with success.\n");

    uint8_t byte;

    while (fread(&byte, byte_size, byte_nb, fptr) == 1) {
        if (debug) {
            print1Byte(byte); printf("\n");
        }
        // Decode first Byte (OPCode, D, W)
        Byte1 *byte1 = getByte1(byte, debug);

        if (strcmp(byte1->opCode, "mov") == 0) {
            uint8_t nextByte;
            if (fread(&nextByte, byte_size, byte_nb, fptr) == 1) {
                if (debug) {
                    print1Byte(nextByte);
                    printf("\n");
                }
                Byte2 *byte2 = getByte2(nextByte, debug);
                Instruction *instr = (Instruction *)malloc(sizeof(Instruction));

                // MOD=11
                if (byte2->mod == 0b11) {
                    instr->opCode = byte1->opCode;

                    // W=1
                    if (byte1->wordOp == 1) {
                        // D=1
                        if (byte1->direction == 1) {
                            instr->destination = binaryToStringW1(byte2->reg);
                            instr->source = binaryToStringW1(byte2->rm);
                        } // D=0
                        else {
                            instr->source = binaryToStringW1(byte2->reg);
                            instr->destination = binaryToStringW1(byte2->rm);
                        }
                    } // W=0
                    else {
                        if (byte1->direction == 1) {
                            instr->destination = binaryToStringW0(byte2->reg);
                            instr->source = binaryToStringW0(byte2->rm);
                        } // D=0
                        else {
                            instr->source = binaryToStringW0(byte2->reg);
                            instr->destination = binaryToStringW0(byte2->rm);
                        }
                    }

                    printf("\n%s %s, %s", instr->opCode, instr->destination, instr->source);
                }

                free(byte2);
                free(instr);
            }
        } else { printf("nope");}
        free(byte1);

    }
    printf("\n");

    fclose(fptr);

    return 0;
}
