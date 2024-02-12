#include "cool_array.h"
#include "cool_array.cpp"  // Assuming this includes the implementation file
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

int argument;

bool getInput() {
    std::string input;
    std::cin >> input;
    if (input == "q" || input == "Q") {
        std::cout << "Quitting... (Press Enter to continue)\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get(); // Wait for Enter key
        return false;
    }
    if (!isdigit(input[0])) {
        std::cout << "Invalid input. Please enter an integer or 'q' to quit.\n";
        return getInput();
    }
    argument = std::stoi(input);
    return true;
}


int main() {

    int input, locArg1, locArg2;
    std::ifstream inFile("A1input.txt");
    CoolArray<int> oda; // Calls the default constructor for the CoolArray class using the template type int, and makes an array with size 10
    oda.loadNumbersFromFile(inFile); // Calls the loadNumbersFromFile member function on oda passing the input file.

    while (true) {
        std::system("cls || clear");
        argument = NULL;
        std::cout << "-------------------------------\n" << std::setw(5) << "" << "Cool Array Pilot Menu" << "\n-------------------------------\n";
        std::cout << std::setw(2) << "" << "Choice : Command Executed\n";
        std::cout << "-------------------------------\n";
        std::cout << std::setw(7) << "" << "1 : CoolPushBack\n";
        std::cout << std::setw(7) << "" << "2 : Remove\n";
        std::cout << std::setw(7) << "" << "3 : Modify\n";
        std::cout << std::setw(7) << "" << "4 : Exists\n";
        std::cout << std::setw(7) << "" << "5 : Print Array\n";
        std::cout << std::setw(7) << "" << "6 : Quit";
        while (true) {
            std::cout << "\nEnter a Choice: ";
            if (std::cin >> input && (input < 7) && (input > 0)) {
                // Input is a valid integer
                break;
            }
            else {
                // Clear the input stream and ignore invalid input
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter an integer between 1 -> 6." << std::endl;
            }
        }
        // Input is valid enter switch:
        switch (input) {
        case 1:
            // Code for case 1
            std::system("cls || clear");
            std::cout << "Please enter the new element to add the back of the array (Q to quit): ";
            if(getInput())
                oda.coolPushback(argument);
            break;
        case 2:
            // Code for case 2
            try {
                std::system("cls || clear");
                std::cout << "Please enter the index of the element to remove from the array (Q to quit): ";
                if (getInput())
                    oda.remove(argument);
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what();
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get(); // Wait for Enter key
            }
            break;
        case 3:
            // Code for case 3
            std::system("cls || clear");
            std::cout << "Please enter the index of the element to modify (Q to quit): ";
            if (getInput()) {
                locArg1 = argument;
                std::cout << "\nPlease enter the new element (Q to quit): ";
                if (locArg2 = getInput()) {
                    locArg2 = argument;
                    try {
                        std::cout << oda.modify(locArg1, locArg2);
                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get(); // Wait for Enter key
                    }
                    catch (const std::out_of_range& e) {
                        std::cout << e.what();
                        std::cout << "\nPress Enter to continue...";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get(); // Wait for Enter key
                    }
                }
            }
            break;
        case 4:
            // Code for case 4
            std::system("cls || clear");
            std::cout << "Please enter the element to find in the array (Q to quit): ";
            if (getInput()) {
                std::cout << oda.exists(argument);
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get(); // Wait for Enter key
            }
            break;
        case 5:
            // Code for case 5
            std::system("cls || clear");
            oda.printArray();
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get(); // Wait for Enter key
            break;
        case 6:
            // Exits Main.
            return EXIT_SUCCESS;
            break;
        default:
            // Default case (for all other values)
            break;
        }
    }

    return EXIT_SUCCESS;
}