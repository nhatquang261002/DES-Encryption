#include "des.h"
#include "const.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ostream>

std::string init_permutation (std::string plain) {
    std::string ip = "";
    std::string plainBin = hexaToBin (plain);

    for (int i = 0; i < 64; i++) {
        ip = ip + plainBin[initial_permutation[i] - 1];
    }

    // outputting plaintext after intial permutation 
    std::cout << std::endl << " The plaintext after intial permutaion: " << ip << std::endl;


    return ip;
}

std::string expansion_permutation (std::string rightPlainText, int round) {
    std::string expanded = "";
    
    //applying the expansion table to the right half of the plaintext 
    for(int i = 0; i < 48; i++) { 
    	expanded += rightPlainText[expansion_table[i]-1]; 
    };  //xoring the right half of plaintext with the intial subkey produced in that round. 
    std::cout << " Expanded: " << expanded << std::endl;
    std::cout << " Key: " << sKey_48bits[round] << std::endl;
	std::string expanded_XOR_key = stringXor(sKey_48bits[round], expanded); 
    
    return expanded_XOR_key;
}

std::string sbox (std::string input) {
    std::string sbox_output = "";
    for (int i = 0; i < 8; i++) {
        std::string r1 = input.substr (i * 6, 1) + input.substr (i * 6 + 5, 1);
        int row = binToDec (r1);
        std::string c1 = input.substr (i * 6 + 1, 1) + input.substr (i * 6 + 2, 1) + input.substr (i * 6 + 3, 1) + input.substr (i * 6 + 4, 1);
        int column = binToDec (c1);
        int ans = s_box_table[i][row][column];
        sbox_output += decToBin (ans);
    }

    return sbox_output;
}

std::string pbox (std::string input) {
    std::string pbox_output = "";
    for (int i = 0; i < 32; i++) {
        pbox_output += input[p_box_table[i] - 1];
    }
    
    return pbox_output;
}



std::string festel_func (std::string ip) {
    std::string right_half = "";
    std::string left_half = "";

    //splitting the plaintext into left and right halfts after initial permuation  has been applied 
    //first half of plaintext is stored in plaintext_lh and the other half is stored in plaintext_rh 
    for(int i = 0; i < 32; i++){
      left_half = left_half + ip[i];
    }

    for(int i = 32; i < 64; i++){
      right_half = right_half + ip[i];
    }

    //outputting th left and right halfs after the intial perm was applied 
    std::cout << " The left half of plaintext after applying IP is: " << left_half << std::endl;
    std::cout << " The right half of the plaintext after applying IP is " << right_half << std::endl; 
    std::endl(std::cout);

    std::string after_rounds = "";

    for (int i = 0; i < 16; i++) {
        // expansion permutation
        std::string expanded_RH = expansion_permutation (right_half, i);
        std::cout << " EP_RH round " << i+1 << " : " << expanded_RH << std::endl;

        // S-Box calculations
        std::string sbox_output = sbox (expanded_RH);
        std::cout << " S Box round " << i+1 << " : " << sbox_output << std::endl;

        // P-Box permute
        std::string pbox_output = pbox (sbox_output);
        std::cout << " P Box round " << i+1 << " : " << pbox_output << std::endl;

        std::string temp = right_half;
        right_half = stringXor (left_half, pbox_output);
        left_half = temp;
        
        std::cout << " Left half round " << i+1 << " : " << left_half << std::endl;
        std::cout << " Right half round " << i+1 << " : " << right_half << std::endl;
        std::cout << std::endl;
    }

    after_rounds = right_half + left_half;
    std::cout << " After rounds: " << after_rounds << std::endl;

    return after_rounds;
}

std::string final_permutation (std::string input) {
    std::string encrypted = "";
    for (int i = 0; i < 64; i++) {
        encrypted += input[inverse_permutation[i] - 1];
    }

    std::cout << "The encrypted text in binary: " << encrypted << std::endl;
    encrypted = binToHex(encrypted);
    std::cout << "The encrypted text in hex: " << encrypted << std::endl;

    return encrypted;
}