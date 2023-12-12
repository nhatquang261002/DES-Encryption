
#include "support.h"
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdint>


std::string hexaToBin (std::string hex) {
    std::string binary = "";
     for (int i = 0; i < hex.size(); i++)
        {
                switch (hex[i])
                {
                case '0': binary = binary + "0000";
             break;
                case '1': binary = binary + "0001";
             break;
                case '2': binary = binary + "0010";
            break;
                case '3': binary = binary + "0011";
            break;
                case '4': binary = binary + "0100";
            break;
                case '5': binary = binary + "0101";
            break;
                case '6': binary = binary + "0110";
            break;
                case '7': binary = binary + "0111";
            break;
                case '8': binary = binary + "1000";
            break;
                case '9': binary = binary + "1001";
            break;
                case 'A':
                case 'a': binary = binary + "1010";
            break;
                case 'B':
                case 'b': binary = binary + "1011";
            break;
                case 'C':
                case 'c': binary = binary + "1100";
            break;
                case 'D':
                case 'd': binary = binary + "1101";
            break;
                case 'E':
                case 'e': binary = binary + "1110";
            break;
                case 'F':
                case 'f': binary = binary + "1111";

            break;

                }

        }
        return binary;
}

 std::string binToHex(std::string binary){

    //loop and switch statment to check groups of four char in binary number and assign them a signle hexadecimal value 
    std::string hexadecimal = "";
        for (int i = 0; i < binary.size(); i = i+4)
        { 

          std::string tempBin = "";

                for (int j = i; j < i + 4; j++)
                        tempBin += binary[j];
                if (tempBin == "0000")
                        hexadecimal = hexadecimal + '0';
                else if (tempBin == "0001")
                        hexadecimal = hexadecimal + '1';
                else if (tempBin == "0010")
                        hexadecimal = hexadecimal + '2';
                else if (tempBin == "0011")
                        hexadecimal = hexadecimal + '3';
                else if (tempBin == "0100")
                        hexadecimal = hexadecimal + '4';
                else if (tempBin == "0101")
                        hexadecimal = hexadecimal + '5';
                else if (tempBin == "0110")
                        hexadecimal = hexadecimal + '6';
                else if (tempBin == "0111")
                        hexadecimal = hexadecimal + '7';
                else if (tempBin == "1000")
                        hexadecimal = hexadecimal + '8';
		        else if (tempBin == "1001")
			            hexadecimal = hexadecimal + '9';
                else if (tempBin == "1010")
                        hexadecimal = hexadecimal + 'A';
                else if (tempBin == "1011")
                        hexadecimal = hexadecimal + 'B';
                else if (tempBin == "1100")
                        hexadecimal = hexadecimal + 'C';
                else if (tempBin == "1101")
                        hexadecimal = hexadecimal + 'D';
                else if (tempBin == "1110")
                        hexadecimal = hexadecimal + 'E';
                else if (tempBin == "1111")
                        hexadecimal = hexadecimal + 'F';
        }
        return hexadecimal;
}

int binToDec (std::string binary) {
    int decimal = 0;
	int j = 0;
	int length = binary.length();
	for(int i = length-1; i >= 0; i--){

    	if(binary[i] == '1'){
        decimal += pow(2, j);
    	}
    j++;
	}
	return decimal;

}

std::string decToBin(int decimal) {
	std::string binary = "";
	while (decimal > 0)
	{
		binary = (char)(decimal % 2 + '0') + binary;
		decimal = decimal / 2;
	}
	while (binary.size() < 4)
		binary = '0' + binary;
	return binary;
}

std::string shiftOnce(std::string key){ 
    std::string keyShifted="";  

        for(int i = 1; i < 28; i++){ 
            keyShifted = keyShifted + key[i]; 
        } 
        keyShifted = keyShifted + key[0];   
    return keyShifted; 
} 
std::string shiftTwice(std::string key){ 
    std::string keyShifted=""; 

    for(int i = 0; i < 2; i++){ 
        for(int j = 1; j < 28; j++){ 
            keyShifted = keyShifted +  key[j]; 
        } 
        keyShifted = keyShifted +  key[0]; 
        key= keyShifted; 
        keyShifted =""; 
    } 
    return key; 
}

std::string stringXor(std::string plainText, std::string key){
        
        std::string xorAnswer = "";
        int s = key.size();
        for(int i = 0; i < s; i++){
                if(plainText[i] != key[i]){
                        xorAnswer = xorAnswer + '1';
                }
                else{
                        xorAnswer = xorAnswer + '0';
                }

                }
                return xorAnswer;
        
}