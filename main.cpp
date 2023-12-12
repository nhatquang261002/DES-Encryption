#include "des.h"
#include "key_transform.h"
#include <iostream>
#include <string>
#include "support.h"



int main () {
    std::cout << "==============================DES Encryption==============================" << std::endl;
    std::cout << std::endl;

    std::string plain = "";
    std::string key = "";

    std::cout <<"Enter 16 character (no space ' ' allowed) plain text for encryption: ";
    getline (std::cin, plain);
    while (plain.size() != 16) {
        std:: cout << std::endl << "The plain text length doesn't fit, please try again: ";
        getline (std::cin, plain);
    }
    std::cout << std::endl;
    // plain = textToHex (plain);
    // std::cout << std::endl <<"Text in hexadecimal: " << plain << std::endl;

    std::cout << std::endl << "Enter 16 character (no space ' ' allowed) key for encryption: ";
    getline (std::cin, key);
    while (key.size() != 16) {
        std:: cout << std::endl << "The key length doesn't fit, please try again: ";
        getline (std::cin, key);
    }
    std::cout << std::endl;
    // key = textToHex (key);
    // std::cout << std::endl <<"Key in hexadecimal: " << key << std::endl;

    keyGen (key);

    std::cout << "-------------Encryption-------------" << std::endl;

    std::string init_permute = init_permutation (plain);
    std::string festel_output = festel_func (init_permute);
    std::string encrypted = final_permutation (festel_output);

    return 0;
}