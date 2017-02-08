#include <iostream>

void decrypt();
void encrypt();

int main() {
    bool quit = false;

    std::cout << ":::::::::::::::::ENCRYPT N DECRYPT:::::::::::::::::\n\n"
              << " by: Rodrigo Martins de Oliveira (github:allrod5)\n"
              << std::endl;

    while(!quit) {
        std::cout << "\n Enter with an elegible option:\n"
                  << "  (default) 0 - encrypt\n"
                  << "            1 - decrypt\n"
                  << "            q - quit"
                  << std::endl;

        char opt = '0';

        std::cin >> opt;

        switch(opt) {
            case '0':
                encrypt();
                break;
            case '1':
                decrypt();
                break;
            case 'q':
                quit = true;
                break;
            default:
                std::cout << "Unrecognized option!" << std::endl;
                break;
        }
    }

    return 0;
}

void decrypt() {

}

void encrypt() {

}
