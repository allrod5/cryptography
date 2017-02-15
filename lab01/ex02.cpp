#include <iostream>
#include <string>

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
    int modifier;
    std::string message, key;

    std::cin.clear();
    std::cout << "::::::::::::::::::::::DECRYPT::::::::::::::::::::::\n\n"
              << " Enter with the encrypted message: \n";

    std::cin.ignore();
    std::getline(std::cin, message);

    std::cout << "\n Type in the decryption key: \n";

    std::getline(std::cin, key);

    for (int i=0; i<message.length(); i++) {
        if (message[i] == ' ') continue;
        modifier = message[i] < 'a' ? (int)'A' : (int)'a';
        std::cout << (char) modifier << ", " << (char) message[i] << ", " << (char) key[i%key.length()] << ", " << (char) (((int)((int)message[i] - (int)key[i%key.length()]) + 26) % 26 + modifier) << "\n"; 
        message[i] = (char) ((((int)((int)message[i] - (int)key[i%key.length()]) + 26) % 26) + modifier);
    }

    std::cout << "\n The decrypted message is:\n\n"
              << message;
}

void encrypt() {

}
