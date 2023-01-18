#include "fermat.h"

unsigned __int64 generateRandomNumber() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937_64 generator(seed);
    //Generate random number
    return generator() % 100000000000000;
}

// Function to display menu options
void displayMenu() {
    std::cout << "Please select an option:" << std::endl;
    std::cout << "1. Create a new key" << std::endl;
    std::cout << "2. Create a new message" << std::endl;
    std::cout << "3. Encrypt the message" << std::endl;
    std::cout << "4. Decrypt the message" << std::endl;
    std::cout << "5. Exit the program" << std::endl;
    std::cout << "6. Ping Google.com" << std::endl;
}

// Function to get user input and validate it
int getInput() {
    int choice;
    std::cin >> choice;
    while (std::cin.fail() || choice < 1 || choice > 6) {
        std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        displayMenu();
        std::cout << "Please select a option: ";
        std::cin >> choice;
    }
    return choice;
}
