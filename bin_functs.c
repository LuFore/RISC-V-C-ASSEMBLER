#include "bin_functs.h"

void uint32_to_binstring(uint32_t arg){ //prints a string of 1s and 0s, should return it later
	char char_arr[32];
	uint32_t r = arg; 
	
	for(uint8_t i = 0; i <= 31; i++){
		char_arr[31 - i] = ((r & 1)== 1) ? '1' : '0';
		r = r >> 1;
	};	
//	char_arr[32] = '\n';//new line
	char_arr[32] = '\0';//terminate string
	printf("%s", char_arr);//print string
};

uint32_t bitmask32(uint8_t end, uint8_t start){ //make a 32 bit bitmask
		//it works a bit like X downto Y in VHDL :)
	uint32_t r = 0;

	for(uint8_t i = 0; i <= (end - start); i++){ 
		r = r << 1;
		r = r or 1;
	}; 
	r = r << start;
	return r;
};

uint32_t bin_combine(uint32_t val1, uint32_t val2, uint8_t end, uint8_t start){
	uint32_t r;
	uint32_t bitmask = bitmask32(end, start);
	//cut hole from val1
	r = val1 & ~bitmask;
	//insert val2
	r = r | ((val2 << start) & bitmask);
	return r;
};

uint64_t ubin_to_uint(char *bin){//suppots up to 64 bits
	uint64_t r = 0;
	uint64_t mult = 1;
 	uint8_t max = strlen(bin);

	for(uint8_t i = 1; i <= max; i++){
		r = (bin[max - i] == '1') ? (mult + r) : r;
		mult = mult* 2 ;
	};
	return r;
};
