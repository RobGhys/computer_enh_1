#include <iostream>
#include <stdlib.h>
#include <stdint.h>

# include "bin_str_map.h"
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

    if(argc!=2) {
        printf("Usage: Add file name as argument");
        exit(1);
    }

    //mov cx, bx
    fptr = fopen(argv[1], "rb");

    if (fptr == NULL) {
        printf("File not open. Exiting the program...");
        exit(0);
    }

    printf("Read file with success.\n");

    uint8_t byte;

    while (fread(&byte, byte_size, byte_nb, fptr) == 1) {
        print1Byte(byte); printf("\n");
        // Decode first Byte (OPCode, D, W)
        Byte1 *byte1 = getByte1(byte);

        if (strcmp(byte1->opCode, "mov") == 0) {
            uint8_t nextByte;
            if (fread(&nextByte, byte_size, byte_nb, fptr) == 1) {
                print1Byte(nextByte);
                printf("\n");
                Byte2 *byte2 = getByte2(nextByte);
                Instruction *instr = (Instruction *)malloc(sizeof(Instruction));

                if (byte2->mod == 0b11) {
                    instr->opCode = byte1->opCode;
                    // W=1 RM=001
                    if ((byte1->wordOp == 1) && (byte2->rm == 0b001)) {
                        if (byte2->reg == 0b011) {
                            //printf("bx ");
                        }
                        if (byte2->rm == 0b001) {
                            //printf("cx");
                        }

                        if (byte1->direction == 1) {
                            instr->source = "cx";
                            instr->destination = "bx";
                        } else {
                            instr->source = "bx";
                            instr->destination = "cx";
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
