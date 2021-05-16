#ifndef RISCV_INST_H
#define RISCV_INST_H
#include <stdint.h>
#include <stdio.h>

#include "bin_functs.h"
#define u32 uint32_t
#define u8 uint8_t

// i is to avoid keywords
typedef enum _instruction{iLUI, iAUIPC, iJAL, iJALR, iBEQ, iBNE, iBLT, iBGE, iBLTU, iBGEU, iLB, iLH, iLW, iLBU, iLHU, iSB, iSH, iSW, iADDI, iSLTI, iSLTIU, iXORI, iORI, iANDI, iSLLI, iSRLI, iSRAI, iADD, iSUB, iSLL, iSLT, iSLTU, iXOR, iSRL, iSRA, iOR, iAND, iFENCE, iECALL, iEBREAK}_instruction;

typedef enum _type {R, I, S, B, U, J}_type;

typedef enum _opcode{LOAD, LOAD_FP, custom_0, MISC_MEM, OP_IMM, AUIPC, OP_IMM_32, op48b, STORE, STORE_FP, custom_1, AMO, OP, LUI, OP_32, op64b, MADD, MSUB, NMSUB, NMADD, OP_FP, reserved0, custom_2_rv128, op48b0, BRANCH, JALR, reserved1, JAL, SYSTEM, reserved2, custom_3_rv128, op80b}_opcode;

struct instruction_info{
//instruction info
_instruction inst;
_type		  type;
_opcode	opcode;
uint16_t funct;
  uint8_t shamt; //if shamt is used, set this to high
//u	ser data, these will want to go in another struct or just as an argument
//uint8_t rs1;
//uint8_t rs2;
//uint8_t rd;
//uint32_t imm;
};




struct instruction_info inst_build( _instruction inst_in);
//Find all characteristics of an instruction and return them in a struct

uint8_t get_opcode( _opcode opcode);
//Gets the machine opcode from the enum

char* opcode2string( _opcode opcode);
char* inst2string(_instruction inst);

uint32_t build_R_type(struct instruction_info inst_in, uint8_t rs1, uint8_t rs2, uint8_t rd);
// builds an R type instruction
uint32_t build_I_type(struct instruction_info inst_in, uint8_t rs1, uint8_t rd, uint16_t imm);
//build and instruction of the I type
uint32_t build_S_type(struct instruction_info inst_in, uint8_t rs1, uint8_t rs2, uint8_t rd, uint16_t imm);
//build and instruction of the S type
uint32_t build_B_type(struct instruction_info inst_in, uint8_t rs1, uint8_t rs2, uint8_t rd, uint16_t imm); 
uint32_t build_U_type(struct instruction_info inst_in, uint8_t rd, uint32_t imm);
uint32_t build_J_type(struct instruction_info inst_in, uint8_t rd, uint32_t imm);
void std_print( _instruction inst, uint8_t rs1, uint8_t rs2, uint8_t rd, uint32_t imm, uint8_t verbose);

#endif

