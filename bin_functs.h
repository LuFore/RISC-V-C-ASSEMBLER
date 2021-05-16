#ifndef BIN_FUNCTS_H
#define BIN_FUNCTS_H
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define or |

void uint32_to_binstring(uint32_t arg);
//converts a 32 bit int to a string of 1s and 0s and prints it, should return it in future

uint32_t bitmask32(uint8_t end, uint8_t start);
//make a 32 bit bitmask, masking bits end to start

uint32_t bin_combine(uint32_t val1, uint32_t val2, uint8_t end, uint8_t start);
//Put the binary value of val2 into val1 between bit end and start

uint64_t ubin_to_uint(char *bin);
//converts a binary number in a string to a uint64

#endif
