#include <algorithm>
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
                  << "            i - information about the encryption system implemented\n"
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
            case 'i':
                std::cout << "This program implements the Vignère cypher.\n"
                        "The implementation adopted transforms every character dealt as input into it's lowercase form.\n"
                        "Spaces are not encrypted nor decrypted and the only expected input are letters and spaces only, no other characters are supported." << std::endl;
                break;
            case 'q':
                quit = true;
                break;
            default:
                std::cout << "Unrecognized option!" << std::endl;
                break;
        }

        std::cin.ignore();
        std::cin.clear();
    }

    return 0;
}

void decrypt() {
    std::string message, key;

    std::cin.clear();
    std::cout << "::::::::::::::::::::::DECRYPT::::::::::::::::::::::\n\n"
              << " Enter with the encrypted message: \n";

    std::cin.ignore();
    std::getline(std::cin, message);
    std::transform(message.begin(), message.end(), message.begin(), ::tolower);

    std::cout << "\n Type in the decryption key: \n";

    std::getline(std::cin, key);
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);

    for (int i=0; i<message.length(); i++) {
        if (message[i] == ' ') continue;
        message[i] = (char) ((((int)message[i] - (int)key[i % key.length()] + 26) % 26) + 'a');
    }

    std::cout << "\n The decrypted message is:\n\n"
              << message;
}

void encrypt() {
    std::string message, key;

    std::cin.clear();
    std::cout << "::::::::::::::::::::::ENCRYPT::::::::::::::::::::::\n\n"
              << " Enter with a message to encrypt: \n";

    std::cin.ignore();
    std::getline(std::cin, message);
    std::transform(message.begin(), message.end(), message.begin(), ::tolower);

    std::cout << "\n Type in the encryption key: \n";

    std::getline(std::cin, key);
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);

    for (int i=0; i<message.length(); i++) {
        if (message[i] == ' ') continue;
        message[i] = (char) ((message[i] + key[i%key.length()] - 2*'a') % 26 + 'a');
    }

    std::cout << "\n The encrypted message is:\n\n"
              << message;
}
