#include "key_transform.h"
#include "const.h"

std::string sKey_48bits [16];

void keyGen (std::string key) {

    std::cout << "-------------Key Generator-------------" << std::endl;

    //convert key to binary
    std::string key_64bits = hexaToBin (key);
    std::cout << "The Key in binary is: " << key_64bits << std::endl;
    std::endl(std::cout);

    // the 56-bits key
    std::string key_56bits = "";
    std::string key_LH = "";
    std::string key_RH = "";

    // permuted choice 1
    for (int i = 0; i < 56; i++){
      key_56bits = key_56bits + key_64bits[permuted_choice_1[i]-1];
    }

    // two side of the key
    for(int i = 0; i < 28; i++){
      key_LH = key_LH + key_56bits[i];
    }
    for(int i = 28; i < 56; i++){
      key_RH = key_RH + key_56bits[i];
    }
    //outputting the left and right subkeys before rounds begin 
    std::cout << " The left half of the key (C0): " << key_LH << std::endl;
    std::cout << " The right half of the key (D0): " << key_RH << std::endl;

    //16 rounds of left and right subkey generation stored in these vars 
    std::string sKey_LH[17];
    std::string sKey_RH[17]; 
    sKey_LH[0] =key_LH;
    sKey_RH[0] =key_RH;

    //applying the appropriate shifts for each according  and displaying them     
    for(int i = 1; i < 17; i++){
            if (i == 1 || i == 2 || i== 9 || i==16 ){
                    sKey_LH[i] = shiftOnce(sKey_LH[i-1]);
                    sKey_RH[i] = shiftOnce(sKey_RH[i-1]);
                    std::cout << " C" << i << " = " <<sKey_LH[i] << std::endl;
                    std::cout << " D" << i << " = " <<sKey_RH[i] << std::endl;
                    
            }

            else{
                    sKey_LH[i] = shiftTwice(sKey_LH[i-1]);
                    sKey_RH[i] = shiftTwice(sKey_RH[i-1]);
                    std::cout << " C" << i << " = " <<sKey_LH[i] << std::endl;
                    std::cout << " D" << i << " = " <<sKey_RH[i] << std::endl;

            }
    }

    std::string sKey_56bits[16];
    for(int i = 0; i < 16; i++){
                    sKey_56bits[i] = sKey_LH[i+1] + sKey_RH[i+1];
            
    }

    for(int i = 0; i < 16; i++){
             sKey_48bits[i] = "";
        for(int j = 0; j < 48; j++){

                sKey_48bits[i] = sKey_48bits[i] + sKey_56bits[i][permuted_choice_2[j] - 1];
               
        }
        std::cout << "Key round " << i + 1 << ": " << sKey_48bits[i] << std::endl;
    }

    std::cout << std::endl;
}