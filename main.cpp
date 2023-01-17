#include "main.h"

#include <limits>
#include <cstdlib>

// Function to display menu options
void displayMenu() {
    std::cout << "Please select an option:" << std::endl;
    std::cout << "1. Create a new key" << std::endl;
    std::cout << "2. Use an existing key" << std::endl;
    std::cout << "3. Create a new message" << std::endl;
    std::cout << "4. Use an existing message" << std::endl;
    std::cout << "5. Encrypt the message" << std::endl;
    std::cout << "6. Decrypt the message" << std::endl;
    std::cout << "7. Exit the program" << std::endl;
    std::cout << "8. Ping Google.com" << std::endl;
}

// Function to get user input and validate it
int getInput() {
    int choice;
    std::cin >> choice;
    while (std::cin.fail() || choice < 1 || choice > 8) {
        std::cout << "Invalid input. Please enter a number between 1 and 8." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        displayMenu();
        std::cout << "Please select a option: ";
        std::cin >> choice;
    }
    return choice;
}

int main() {
    std::string key, message, userMessageFile, userKeyFile;
    std::string newRandomKey;
    int choice;

    while (true) {
        displayMenu();
        // Ask user for input
        std::cout << "Enter your choice: ";
        choice = getInput();
        std::ofstream keyFile;
        std::string newMessage;
        //Create the encrypted and decrypted variables
        std::string encryptedMessage;
        std::string decryptedMessage;
        std::ifstream messageFile;
        std::string messageString;
        std::string fileName;
        std::string fileNameNewMessage;
        std::ofstream file(fileName);
        unsigned __int64 d = generateRandomNumber();

        switch (choice) {
            case 1:
                std::cout << "Creating a new key..." << std::endl;
                // code to create new key
                //Print out the Decryption Key
                std::cout << "Key: " << d << "\n";
                //Write the key to a file, ask user what to name the decrypt file
                std::cout << "Enter the name of the file to save the key to: ";
                std::cin >> fileName;
                file.open(fileName);
                file << d;
                file.close();
                //Inform the user that the key has been saved
                std::cout << "Key saved to " << fileName << "\n";
                break;
            case 2:
                std::cout << "Using an existing key..." << std::endl;
                // code to use existing key
                break;
            case 3:
                std::cout << "Creating a new message..." << std::endl;
                //create a new message and save it to a file
                //Enter a message to encrypt
                std::cout << "Enter a message to encrypt: ";
                std::cin >> newMessage;
                //Save message to file name given by user
                std::cout << "Enter a name for the message file: ";
                std::cin >> fileNameNewMessage;
                keyFile.open(fileNameNewMessage);
                keyFile << newMessage;
                keyFile.close();
                //Inform user that message has been saved
                std::cout << "Message saved to file: " << fileNameNewMessage << std::endl;
                std::cout << "MAKE SURE TO ENCRYPT THE MESSAGE WITH A KEY BEFORE SENDING IT TO ANYONE!" << std::endl;
                break;
            case 4:
                std::cout << "Using an existing message..." << std::endl;
                // code to use existing message
                break;
            case 5:
                std::cout << "Encrypting the message..." << std::endl;
                //Get a message file name from the user
                std::cout << "Enter the name of the message file: ";
                std::cin >> userMessageFile;
                //open the message file and save it to a string
                messageFile.open(userMessageFile);
                messageFile >> messageString;
                messageFile.close();
                //Show the user the message that will be encrypted
                std::cout << "Message to encrypt: " << messageString << std::endl;
                //Get the key file name from the user
                std::cout << "Enter the name of the key file: ";
                std::cin >> userKeyFile;
                //Open the key file and save it to a string
                messageFile.open(userKeyFile);
                messageFile >> key;
                messageFile.close();
                //Show the user the key that will be used to encrypt the message
                std::cout << "Key to encrypt with: " << key << std::endl;
                //Encrypt the message with the new key using a julius caesar cipher
                for (int i = 0; i < messageString.length(); i++) {
                    encryptedMessage += (char) (messageString[i] - std::stoi(key));
                }
                //Show the user the encrypted message
                std::cout << "Encrypted message: " << encryptedMessage << std::endl;
                //Save the encrypted message to a file
                std::cout << "Enter a name for the encrypted message file: ";
                std::cin >> fileName;
                keyFile.open(fileName);
                keyFile << encryptedMessage;
                keyFile.close();
                //Inform user that message has been saved
                std::cout << "Encrypted message saved to file: " << fileName << std::endl;

                break;
            case 6:
                std::cout << "Decrypting the message..." << std::endl;
                // code to decrypt the message
                break;
            case 7:
                std::cout << "Exiting the program..." << std::endl;
                return 0;
            case 8:
                std::cout << "Pinging Google.com 50 times...." << std::endl;
                //Ping google.com 50 times
                for (int i = 0; i < 5; i++) {
                    std::string IP ("8.8.8.8");
                    std::string command = "ping -n 10 " + IP;
                    std::system(command.c_str());
                }
                break;
        }
    }

}











/*


    switch (selection) {
        case 1:
            std::cout << "You selected to create a new key." << std::endl;
            //Create a new key
            std::cout << "Your new key is: " << d << std::endl;

            break;
        case 2:
            std::cout << "You selected to use an existing key." << std::endl;
            //Use an existing key

            break;
        case 3:
            std::cout << "You selected to create a new message." << std::endl;
            break;
        case 4:
            std::cout << "You selected to use an existing message." << std::endl;
            break;
        case 5:
            std::cout << "You selected to encrypt the message." << std::endl;
            break;
        case 6:
            std::cout << "You selected to decrypt the message." << std::endl;
            break;
        case 7:
            std::cout << "You selected to exit the program." << std::endl;
            break;
        default:
            std::cout << "You did not enter a valid selection." << std::endl;
            break;
    }


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
} */
