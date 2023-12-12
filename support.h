#ifndef SUPPORT_H
#define SUPPORT_H
 
#include <iostream>
#include <math.h>

// convert hexa to binary
std::string hexaToBin (std::string);

// convert binary to hexa
std::string binToHex (std::string);

// convert binary to dec
int binToDec (std::string);

// convert dec to binary
std::string decToBin (int dec);

// left shifts 1 time
std::string shiftOnce (std::string);

// left shifts 2 times
std::string shiftTwice (std::string);

// xor 2 strings helper
std::string stringXor (std::string, std::string);

#endif