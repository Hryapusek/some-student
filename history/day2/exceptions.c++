#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>  // For std::runtime_error

// Throws exceptions on failure (no error codes needed)
std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("File not found: " + filename);
    }

    std::string content;
    if (!std::getline(file, content)) {
        throw std::runtime_error("Failed to read file: " + filename);
    }

    return content;  // No manual cleanup needed (RAII)
}

int main() {
    try {
        std::string data = readFile("data.txt");
        std::cout << "File content: " << data << "\n";
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}