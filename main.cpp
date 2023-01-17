#include "main.h"

int main() {

    unsigned __int64 d = generateRandomNumber();
    //Print out the Decryption Key
    std::cout << "Exponent: " << d << "\n";

    //Write the key to a file, ask user what to name the decrypt file
    std::string fileName;
    std::cout << "Enter the name of the file to save the key to: ";
    std::cin >> fileName;
    std::ofstream file(fileName);
    file << d;
    file.close();

    //Inform user that the key has been written to a file
    std::cout << "Decryption Key has been written to " << fileName << std::endl;
    //Pause the program
    std::cin.get();
    //Enter a message to encrypt
    std::string message;
    std::cout << "Enter a message to encrypt: ";
    std::getline(std::cin, message);

    //Create the encrypted and decrypted variables
    std::string encryptedMessage;
    std::string decryptedMessage;

    //Encrypt the message with a julius cipher
    for (int i = 0; i < message.length(); i++) {
        encryptedMessage += (char) (message[i] + d);
    }

    //Display the encrypted message
    std::cout << "Encrypted Message: " << encryptedMessage << "\n";
    //Save the encrypted message to a file
    std::string encryptedFileName;
    std::cout << "Enter the name of the file to save the encrypted message to: ";
    std::cin >> encryptedFileName;
    std::ofstream encryptedFile(encryptedFileName);
    encryptedFile << encryptedMessage;
    encryptedFile.close();
    //Inform user that the encrypted message has been written to a file
    std::cout << "Encrypted Message has been written to " << encryptedFileName << std::endl;


    //If the user does not want to decrypt the message, display a message and exit the program
    std::cout << "Would you like to decrypt the message? (y/n): ";
    std::string answer;
    std::cin >> answer;
    if (answer == "y") {
        std::string location;

        while (true) {
            std::cout << "Enter the location of the decryption key: ";
            std::cin >> location;
            std::ifstream file(location);
            if (file.is_open()) {
                break;
            } else {
                std::cout << "Invalid location, please try again.\n";
            }
        }
        //Open the file
        std::ifstream file(location);
        //Read the file
        std::string key;
        file >> key;
        //Close the file
        file.close();
        //Decrypt the message

        unsigned __int64 keyInt = std::stoull(key);
        for (int i = 0; i < encryptedMessage.length(); i++) {
            decryptedMessage += (char) (encryptedMessage[i] - keyInt);
        }
        std::cout << "Decrypted Message: " << decryptedMessage << "\n";
    }
    //If the user does not input y then do not decrypt the message
    else {
        std::cout << "Message not decrypted\n";
    }

    return 0;
}