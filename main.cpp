#include "main.h"

int main() {
    std::string key, message, userMessageFile, userKeyFile;
    int choice;

    while (true) {
        displayMenu();
        // Ask user for input
        std::cout << "Enter your choice: ";
        choice = getInput();
        std::string newMessage;
        //Create the encrypted and decrypted variables
        std::string encryptedMessage;
        std::string decryptedMessage;
        std::ifstream messageFile;
        std::string messageString;
        std::string fileName;
        std::string fileNameNewMessage;
        std::ofstream keyFile(fileNameNewMessage);
        std::ofstream file(fileName);
        unsigned __int64 d = generateRandomNumber();

        switch (choice) {

            /* CREATE A NEW KEY */
            case 1:
                std::cout << "Creating a new key..." << std::endl;
                std::cout << "Key: " << d << "\n";

                /* WRITE KEY TO FILE */
                std::cout << "Enter the name of the file to save the key to: ";
                std::cin >> fileName;
                file.open(fileName);
                file << d;
                file.close();
                std::cout << "Key saved to " << fileName << "\n";

                /*END OF NEW KEY: CASE 1*/
                break;


            /* CREATE A NEW MESSAGE */
            case 2:
                std::cout << "**CREATE A MESSAGE***" << std::endl;

                /* GET MESSAGE FROM USER */
                std::cout << "Enter a message to encrypt: ";
                std::getline(std::cin >> std::ws, newMessage);
                std::cout << std::endl;

                /* SAVE MESSAGE TO FILE */
                std::cout << "Enter a name for the message file: ";
                std::getline(std::cin >> std::ws, fileNameNewMessage);
                keyFile.open(fileNameNewMessage);
                keyFile << newMessage;
                keyFile.close();
                std::cout << "Message saved to file: " << fileNameNewMessage << std::endl;

                /* WARN USERS TO ENCRYPT THEIR DATA */
                std::cout << "MAKE SURE TO ENCRYPT THE MESSAGE WITH A KEY BEFORE SENDING IT TO ANYONE!" << std::endl;

                /*END OF NEW MESSAGE: CASE 2*/
                break;


            /* ENCRYPTION */
            case 3:
                /*WORKING AS OF NOW*/
                std::cout << "****ENCRYPT A MESSAGE****" << std::endl;
                std::cout << "Enter the name of the message file: ";
                std::cin >> userMessageFile;

                /* OPEN SECRET MESSAGE FILE AND STORE ALL DATA */
                messageFile.open(userMessageFile);
                if (messageFile.is_open()) {
                    while (std::getline (messageFile, messageString)) {
                        message += messageString;
                    }
                    messageFile.close();
                } else {
                    std::cout << "Unable to open file";
                }
                std::cout << "Message to encrypt: " << messageString << std::endl;

                /* OPEN PRIVATE KEY FILE */
                std::cout << "Enter the name of the key file: ";
                std::cin >> userKeyFile;
                messageFile.open(userKeyFile);
                messageFile >> key;
                messageFile.close();
                std::cout << "Key to encrypt with: " << key << std::endl;

                /*ENCRYPT DATA*/
                for (int i = 0; i < messageString.length(); i++) {
                    encryptedMessage += (char) (messageString[i] - std::stoull(key));
                }
                std::cout << "Encrypted message: " << encryptedMessage << std::endl;

                /*SAVE TO FILE*/
                std::cout << "Enter a name for the encrypted message file: ";
                std::cin >> fileName;
                keyFile.open(fileName);
                keyFile << encryptedMessage;
                keyFile.close();
                std::cout << "Encrypted message saved to file: " << fileName << std::endl;

                /* END OF ENCRYPTION: CASE 3 */
                break;

            case 4:
                std::cout << "***DECRYPT A MESSAGE***" << std::endl;
                std::cout << "Enter the name of the message file to decrypt: ";

                /* OPEN SECRET MESSAGE FILE */
                std::cin >> userMessageFile;
                messageFile.open(userMessageFile);
                messageFile >> messageString;
                messageFile.close();
                std::cout << "Message to decrypt: " << messageString << std::endl;

                /* OPEN PRIVATE KEY FILE */
                std::cout << "Enter the name of the key file: ";
                std::cin >> userKeyFile;
                messageFile.open(userKeyFile);
                messageFile >> key;
                messageFile.close();
                std::cout << "Key to decrypt with: " << key << std::endl;

                /*DECRYPT DATA*/
                for (int i = 0; i < messageString.length(); i++) {
                    decryptedMessage += (char) (messageString[i] + std::stoull(key));
                }

                /*DISPLAY DECRYPTED MESSAGE*/
                std::cout << "Decrypted message: " << decryptedMessage << std::endl;

                /* END OF DECRYPTION: CASE 4 */
                break;

            /* EXIT THE PROGRAM */
            case 7:
                std::cout << "Exiting the program..." << std::endl;
                return 0;

            /* TEST NETWORK FUNCTIONALITY */
            case 8:
                std::cout << "Pinging Google.com 50 times...." << std::endl;
                //Ping google.com 50 times
                for (int i = 0; i < 5; i++) {
                    std::string IP ("8.8.8.8");
                    std::string command = "ping -n 10 " + IP;
                    std::system(command.c_str());
                }
                /* END OF TEST NETWORK FUNCTIONALITY: CASE 8 */
                break;
        }
    }

}
