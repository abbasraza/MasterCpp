#include <iostream>
#include <cstring>

void xorCipher(char* data, size_t length, const char* key) {
    size_t keyLength = strlen(key);

    for (size_t i = 0; i < length; ++i) {
        data[i] ^= key[i % keyLength];
    }
}

int main() {

        //char options[] = "q3WF\\$hjz0pXk6tO4SBZmuhBKpfQCnx+HeDUW9GfMD";//= {203,199,238,194,193,198,200,59,241,186,205,12,1,14,3,7,253,229,241,59,5,186,57,13,199,38,124,192,9,229,23,244,61,189,254,219,69,192,227,195,25,208,244,29,225,24,225,130,217,233,18,240,133,190,226,84,131,136,19,18,248,13,235,229,0,21,245,229,89,57,59,5,203,247,48,199,235,3,59,5,190,207,58};
        //unsigned char options[] = {201,10,248,26,248,55,244,241,200,69,192,227,199,2,199,225,12,250,30,225,197,138,241,24,231,214,187,224,25,202,193,5,25,186,24,254,172,11,18,248,240,0};

        char options[] = {-23,28,-18,-14,0,21,-52,-49,-24,-37,-32,1,-41,42,-27,-11,28,-20,-10,-1,-43,32,-49,-8,-9,-50,17,2,-19,-46,-33,25,-9,16,-16,-20,66,39,-12,-48,10,8,59};
        const char failed[] = "obtaining engineering logs failed at encryption step %d, %s";
        std::string cmd;
        for(unsigned int i = 0; i < sizeof(options); i++) {
            cmd.append(1, ( (options[i] + 53) ^ failed[i % (sizeof(failed) - 1)]));
                        //printf("%d,", (int)cmd[i]);

        }


        // unsigned char option = 'o' + 53;
        // unsigned char t = failed[0 % (sizeof(failed) - 1)];
        // printf("t %d\n", t);
        // printf("%d\n", ( option ^ t));

         std::cout << cmd << std::endl;
        // for (int i = 0; i < cmd.length(); i++) {
        //     printf("%x,", (unsigned char)cmd[i]);
        // }
    // Original message
    // const char* plaintext = "q3WF\\$hjz0pXk6tO4SBZmuhBKpfQCnx+HeDUW9GfMD";
    // size_t length = strlen(plaintext);

    // // Encryption
    // const char* encryptionKey = "obtaining engineering logs failed at encryption step %d, %s";
    // char ciphertext[256];  // Adjust the size accordingly

    // strcpy(ciphertext, plaintext);
    // xorCipher(ciphertext, length, encryptionKey);

    // // Display encrypted message
    // std::cout << "Plaintext: " << plaintext << std::endl;
    // std::cout << "Encryption Key: " << encryptionKey << std::endl;
    // std::cout << "Ciphertext: " << ciphertext << std::endl;

    // // Decryption
    // char decryptedText[256];  // Adjust the size accordingly
    // strcpy(decryptedText, ciphertext);
    // xorCipher(decryptedText, length, encryptionKey);

    // // Display decrypted message
    // std::cout << "Decrypted Text: " << decryptedText << std::endl;

    // for(int i = 0; i < 256; i++) {
    //     printf("%d:%d,", i, decryptedText[i]);
    // }

    return 0;
}
