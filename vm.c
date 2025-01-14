#include <stdint.h>

#define MEMORY_MAX (1 << 16) /* declare macro, left shift 16 = 65536 */
uint16_t memory[MEMORY_MAX]; /* 65536 total locations = 128KB total */

enum {
    R_R0 = 0, /* R0 - R7 General Purpose Registers */
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, /* Program Counter */
    R_COND, /* Conditional Flags */
    R_COUNT /* Total number of registers: 10 */
};
uint16_t reg[R_COUNT]; 

enum {
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};

enum {               /* R_COND Conditional Flags */
    FL_POS = 1 << 0, /* Positive */
    FL_ZRO = 1 << 1, /* Zero */
    FL_NEG = 1 << 2, /* Negative */
};

int main(int argc, const char* argv[]) {

    if (argc < 2) {
        printf("lc3 [image-file1] ...\n");
        exit(2);
    }

    for (int j = 1; j < argc; j++) {
        if (!read_image(argv[j])) {
            printf("Failed to load image: %s\n", argv[j]);
            exit(1);
        }
    }

    reg[R_COND] = FL_ZRO; /* Initialize the condition flag to zero */

    enum { PC_START = 0x3000 }; /* Program counter starting address */
    reg[R_PC] = PC_START;

    int running = 1;
    while(running) {
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op_code = instr >> 12; /* get the 4 bit opcode */

        switch(op_code) {
            case OP_ADD: 
                break;
            case OP_AND: 
                break;
            case OP_NOT: 
                break;
            case OP_BR: 
                break;
            case OP_JMP: 
                break;
            case OP_JSR: 
                break;
            case OP_LD:   
                break;
            case OP_LDI: 
                break;
            case OP_LDR: 
                break;
            case OP_LEA: 
                break;
            case OP_ST:   
                break;
            case OP_STI: 
                break;
            case OP_STR: 
                break;
            case OP_TRAP:   
                break;
            case OP_RES: 
            case OP_RTI: 
            default: 
                break;
        }
    }

}