#ifndef DES_H
#define DES_H

#include <iostream>
#include "key_transform.h"
#include "support.h"




// initial permutation
std::string init_permutation (std::string);

// expansion permutation
// takes 'right_half_text' and 'rounds_index' as input
// RHT will be expanded and permuted, and then XOR with the key[rounds_index]
std::string expansion_permutation (std::string, int);

// sbox
// takes expansion_permutation's output as input
// divide to 8 blocks
// each block will take its b1b6 as row number, and b2b3b4b5 as column number then takes 4-bit sbox from the sbox_table
std::string sbox (std::string);

// pbox
// takes sbox_output as input
std::string pbox (std::string);

// festel function
// takes initial permutation output as input
// returns 64-bit output
std::string festel_func (std::string);

// final permutation
// takes 64-bit festel_rounds as input
// return cipher text
std::string final_permutation (std::string);

#endif