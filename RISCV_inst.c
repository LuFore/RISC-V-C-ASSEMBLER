#include "RISCV_inst.h"

struct instruction_info inst_build( _instruction inst_in){ //this is a mega switch statement 
	struct instruction_info r;
	r.inst = inst_in;	
	r.funct = 0; //deafult those without functs to 0
	r.shamt = 0;
	switch(inst_in){
		case iLUI :
			r.type = U;
			r.opcode = LUI;
			break;
		case iAUIPC :
			r.type = U;
			r.opcode = AUIPC;
			break;
// Branch instructions
		case iJAL :
			r.type = J;
			r.opcode = JAL;
			break;
		case iJALR :
			r.type = I;
			r.opcode = JALR;
			r.funct = 0;
			break;
		case iBEQ :
			r.type = B;
			r.opcode = BRANCH;
			r.funct = 0;
			break;		
		case iBNE :
			r.type = B;
			r.opcode = BRANCH;
			r.funct = 1;
			break;
		case iBLT :
			r.type = B;
			r.opcode = BRANCH;
			r.funct = ubin_to_uint("100");
			break;
		case iBGE :
			r.type = B;
			r.opcode = BRANCH;
			r.funct = ubin_to_uint("101");
			break;
		case iBLTU :
			r.type = B;
			r.opcode = BRANCH;
			r.funct = 0;
			r.funct = ubin_to_uint("110");
			break;
		case iBGEU : 
			r.type = B;
			r.opcode = BRANCH;
			r.funct = ubin_to_uint("111");
			break;
//load instructions
		case iLB :
			r.type = I;
			r.opcode = LOAD;
			r.funct = 0;
			break;
		case iLH :
			r.type = I;
			r.opcode = LOAD;
			r.funct = 1;
			break; 
		case iLW :
			r.type = I;
			r.opcode = LOAD;
			r.funct = 2;
			break;
		case iLBU :
			r.type = I;
			r.opcode = LOAD;
			r.funct = 4;
			break;
		case iLHU :
			r.type = I;
			r.opcode = LOAD;
			r.funct = ubin_to_uint("101");
			break;
//store instructions
		case iSB :
			r.type = S;
			r.opcode = STORE;
			r.funct = 0;
			break;
		case iSH :
			r.type = S;
			r.opcode = STORE;
			r.funct = 1;
			break;
		case iSW :
			r.type = S;
			r.opcode = STORE;
			r.funct = ubin_to_uint("10");
			break;
//ALU stuff
	        case iADDI :
		  r.type = I;
		  r.opcode = OP_IMM;
		  r.funct = 0;
		  break;
		  
	case iSLTI :
	  r.type = I;
	  r.opcode = OP_IMM;
	  r.funct = ubin_to_uint("010");
	  break;
	case iSLTIU :
	  r.type = I;
	  r.opcode = OP_IMM;
	  r.funct = ubin_to_uint("011");
	  break;
	case iXORI :
	  r.type = I;
	  r.opcode = OP_IMM;
	  r.funct = ubin_to_uint("100");
	  break;
	case iORI :
	  r.type = I;
	  r.opcode = OP_IMM;
	  r.funct = ubin_to_uint("110");
	  break;
	case iANDI :
	  r.type = I;
	  r.opcode = OP_IMM;
	  r.funct = ubin_to_uint("111");
	  break;
	case iSLLI :
	  r.type = I;
	  r.opcode = OP_IMM;
	  r.funct = ubin_to_uint("001");
	  r.shamt = 1;
	  break;
	case iSRLI :
	  r.type = I;
	  r.opcode = OP_IMM;
	  r.funct = ubin_to_uint("101");
	  r.shamt = 1;
	  break;
	case iSRAI :
	  r.type = I;
	  r.opcode = OP_IMM;
	  r.funct = ubin_to_uint("0100000101");
	  r.shamt = 1;
	  break;
	case iADD :
	  r.type = R;
	  r.opcode = OP;
	  r.funct = 0;
	  break;
	case iSUB :
	  r.type = R;
	  r.opcode = OP;
	  r.funct = ubin_to_uint("0100000000");
	  break;
	case iSLL :
	  r.type = R;
	  r.opcode = OP;
	  r.funct = ubin_to_uint("101");
	  break;
	case iSLT :
	  r.type = R;
	  r.opcode = OP;
	  r.funct = ubin_to_uint("010");
	  break;
	case iSLTU :
	  r.type = R;
	  r.opcode = OP;
	  r.funct = ubin_to_uint("011");
	  break;
	case iXOR :
	  r.type = R;
	  r.opcode = OP;
	  r.funct = ubin_to_uint("100");
	  break;
	case iSRL :
	  r.type = R;
	  r.opcode = OP;
	  r.funct = ubin_to_uint("101");
	  break;
	case iSRA :
	  r.type = R;
	  r.opcode = OP;
	  r.funct = ubin_to_uint("0100000101");
	  break;
	case iOR :
	  r.type = R;
	  r.opcode = OP;
	  r.funct = ubin_to_uint("110");
	  break;
	case iAND :
	  r.type = R;
	  r.opcode = OP;
	  r.funct = ubin_to_uint("111");
	  break;
		default: 
		 //display error message maybe
			r.type  = I;
	};
	return r;
};

uint8_t get_opcode( _opcode opcode){ //returns a 7 bit opcode as an 8 bit int
	uint8_t r = 0;
	r = opcode;
	r = r << 2;
	r = r or 3; // add additional 2 bits at bottom 
	return r;
};

char* opcode2string(_opcode opcode){
  const char* strings[] = {"LOAD","LOAD_FP","custom_0","MISC_MEM","OP_IMM","AUIPC","OP_IMM_32","op48b","STORE","STORE_FP","custom_1","AMO","OP","LUI","OP_32","op64b","MADD","MSUB","NMSUB","NMADD","OP_FP","reserved0","custom_2_rv128","op48b0","BRANCH","JALR","reserved1","JAL","SYSTEM","reserved2","custom_3_rv128","op80b"};
  return strings[opcode];
};

char* inst2string(_instruction inst){
  const char* strings[] = {"iLUI","iAUIPC","iJAL","iJALR","iBEQ","iBNE","iBLT","iBGE","iBLTU","iBGEU","iLB","iLH","iLW","iLBU","iLHU","iSB","iSH","iSW","iADDI","iSLTI","iSLTIU","iXORI","iORI","iANDI","iSLLI","iSRLI","iSRAI","iADD","iSUB","iSLL","iSLT","iSLTU","iXOR","iSRL","iSRA","iOR","iAND","iFENCE","iECALL","iEBREAK"};
  return strings[inst];
};

uint32_t build_R_type(struct instruction_info inst_in, uint8_t rs1, uint8_t rs2, uint8_t rd){
  uint32_t r = 0;
	r = get_opcode(inst_in.opcode);
	r = bin_combine(r, rd, 11, 7);
	r = bin_combine(r, inst_in.funct, 14, 12);
	r = bin_combine(r, rs1, 19, 15);
	r = bin_combine(r, rs2, 24, 20);
	r = bin_combine(r, (inst_in.funct >> 3), 31, 25);  
	return r;
};

uint32_t build_I_type(struct instruction_info inst_in, uint8_t rs1, uint8_t rd, uint16_t imm){
	uint32_t r = 0; 
	
	r = get_opcode(inst_in.opcode);
	r = bin_combine(r, rd, 11, 7);
	r = bin_combine(r, inst_in.funct, 14, 12);
	r = bin_combine(r, rs1, 19, 15);
	r = bin_combine(r, imm, 31, 20);
	r = (inst_in.shamt==1) ? bin_combine(r,(imm >> 3), 31, 25) : r;  
	return r;
};

uint32_t build_S_type(struct instruction_info inst_in, uint8_t rs1, uint8_t rs2, uint8_t rd, uint16_t imm){
	uint32_t r = 0; 
	if( rs1 > 32 || rs2 > 32){ //check for incorrect value of rs1 and 2
		printf("rs1 or rs2 too large for register");
	}else{
		r = get_opcode(inst_in.opcode);
		r = bin_combine(r, imm, 11, 7);
		r = bin_combine(r, inst_in.funct, 14, 12);
		r = bin_combine(r, rs1, 19, 15);
		r = bin_combine(r, rs2, 24, 20);
		r = bin_combine(r, (imm >> 5), 31, 25);
	};
	return r;
};

uint32_t build_B_type(struct instruction_info inst_in, uint8_t rs1, uint8_t rs2, uint8_t rd, uint16_t imm){
	u32 r = 0;
	r = get_opcode(inst_in.opcode);
	r = bin_combine(r, (imm >> 11), 7,7);
	r = bin_combine(r, (imm >> 1 ), 11,8);
	r = bin_combine(r, inst_in.funct, 14,12);
	r = bin_combine(r, rs1, 19, 15);
	r = bin_combine(r, rs2, 24, 20);
	r = bin_combine(r, (imm >> 5), 30, 25);
	r = bin_combine(r, (imm >>12), 31, 31);
	return r;
};

uint32_t build_U_type(struct instruction_info inst_in, uint8_t rd, uint32_t imm){
	u32 r = 0;
	r = get_opcode(inst_in.opcode);
	r = bin_combine(r, rd, 11, 7);
	r = bin_combine(r, (imm >> 12), 31, 12);	
	return r;
};

uint32_t build_J_type(struct instruction_info inst_in, uint8_t rd, uint32_t imm){
	u32 r = 0;
	r = get_opcode(inst_in.opcode);
	r = bin_combine(r, rd, 11, 7);
	
	r = bin_combine(r, (imm >> 12), 19,12);
	r = bin_combine(r, (imm >> 11), 20,20);
	r = bin_combine(r, (imm >> 1), 30,21);
	r = bin_combine(r, (imm >> 20), 31,31);
	return r;
};

void std_print( _instruction inst, uint8_t rs1, uint8_t rs2, uint8_t rd, uint32_t imm, uint8_t verbose){
	struct instruction_info inst_inst;
	uint32_t r = 0;

	
	inst_inst = inst_build(inst);
	printf("%u ", inst_inst.type);
	switch(inst_inst.type){
	  case R :
	    r = build_R_type(inst_inst, rs1, rs2, rd);
	    break;
		case I : 
			r = build_I_type(inst_inst, rs1, rd, imm);
			break;
		case S :
			r = build_S_type(inst_inst, rs1, rs2, rd, imm);
			break;
		case B : 
			r = build_B_type(inst_inst, rs1, rs2, rd, imm);
			break;
		case U :
			r = build_U_type(inst_inst, rd, imm);
			break;
		case J :
			r = build_J_type(inst_inst, rd, imm);
			break;
		default :
	 		break;
	}
	uint32_to_binstring(r);
	
	if(verbose == 'v'){
		printf(" , rs1: %u , rs2: %u, rd %u , %u imm\n", rs1, rs2, rd, imm);
	}else{
		printf("\n");
	};
};

int main(void){
	printf("start \n");/*
	std_print(iLBU, 0, 0, 0, 0, 'v');
	std_print(iLW, 14, 15, 20, 42, 0);	
	std_print(iSB,0,0,0,0xFFFF, 0); //this imm is way to big but only for reasons of testing
	std_print(iLBU, 2, 0, 2, 0XFFFF, 'v');	//imm is actually -1
	std_print(iLB, 0, 0, 0, 0, 0);	// imm/rd/the rest doesn't matter
	std_print(iLH, 0, 0, 0, 0, 0);	// imm/rd/the rest doesn't matter
	std_print(iSH, 1, 1, 1 ,1, 1); // just so a difference can be seen in the wave file
	std_print(iSW, 0, 0, 0 ,0, 0); // just so a difference can be seen in the wave file
	*//*
	std_print(iJAL, 0,0, 20, 50, 'v');
	std_print(iJALR, 2,0,21, 30, 'v');
	std_print(iBEQ, 0,1,2,3, 'v');
	std_print(iBNE, 2,3,4,5,'v');
	std_print(iBLT, 3,4,5,6, 'v');
	*/
	for(uint8_t i = iADDI; i <= iAND; i++){
	  printf("opcode:\n %s\n machine code:\n ", inst2string(i));
	  std_print(i, 0, 0, 0, 0, '0');
	}

	//std_print(iBGE, 1,1,0,0,'v');
	//std_print(iBLT, 31, 0, 0, 0, 'v');
	//std_print(iJAL, 0,0,0,0xFFFFFFFF, 'v');
	//std_print(iBNE, 0,0,0,0, 'v');
	//std_print(iBGE, 0,0,0,0, 'v');
	//printf("ADDI = %u , %u", iADDI, iAND);
	return 0;
};
