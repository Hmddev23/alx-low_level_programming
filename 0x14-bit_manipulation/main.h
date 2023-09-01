#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>

unsigned int convert_binary_to_uint(const char *binary_string);
void print_binary_representation(unsigned long int number);
int get_bit_at_index(unsigned long int number, unsigned int index);
int set_bit_at_index(unsigned long int *number, unsigned int index);
int clear_bit_at_index(unsigned long int *number, unsigned int index);
unsigned int count_different_bits(unsigned long int num1, unsigned long int num2);
int check_endianness(void);

#endif /* MAIN_H */
