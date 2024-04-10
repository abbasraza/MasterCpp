#include <iostream>
#include <cstring>

void xorCipher(char* data, size_t length, const char* key) {
    size_t keyLength = strlen(key);

    for (size_t i = 0; i < length; ++i) {
        data[i] ^= key[i % keyLength];
    }
}

int main() {


        char options[] = {-23,28,-18,-14,0,21,-52,-49,-24,-37,-32,1,-41,42,-27,-11,28,-20,-10,-1,-43,32,-49,-8,-9,-50,17,2,-19,-46,-33,25,-9,16,-16,-20,66,39,-12,-48,10,8,59};
        const char failed[] = "helloworld";
        std::string cmd;
        for(unsigned int i = 0; i < sizeof(options); i++) {
            cmd.append(1, ( (options[i] + 53) ^ failed[i % (sizeof(failed) - 1)]));
                        //printf("%d,", (int)cmd[i]);

        }

         std::cout << cmd << std::endl;

    return 0;
}
