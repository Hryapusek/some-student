// Написать простое RAII для FileHandler

#include <iostream>
#include <istream>
#include <ostream>

int main() {

    std::string word{"abc"};
    int number = 100;

    std::cout << "Enter a word: ";
    std::cin >> word;

    if (std::cin.fail()) {
        std::cerr << "Failed to read the word " << word << std::endl;
        return 2;
    }

    std::cout << "Enter a number: ";
    std::cin >> number;

    if (std::cin.fail()) {
        std::cerr << "Failed to read the number " << number << std::endl;
        return 2;
    }

    std::cout << "You entered the word: " << word << std::endl;
    std::cout << "You entered the number: " << number << std::endl;

    // std::ifstream file("alexander.txt");

    // if (!file.is_open())
}