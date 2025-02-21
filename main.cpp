#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_READ 1
#define BYTE_SIZE 1

void printBinary(unsigned char byte) {
    int i;
    for (i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
    printf(" ");
}

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

    if (fptr==NULL) {
        printf("File not open. Exiting the program...");
        exit(0);
    }

    printf("Read file with success.\n");

    unsigned char byte;
    while (fread(&byte, byte_size, byte_nb, fptr) == 1) {
        printBinary(byte);
    }
    printf("\n");

    fclose(fptr);

    return 0;
}