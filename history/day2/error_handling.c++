#include <iostream>
#include <fstream>
#include <string>

// Returns nullptr on failure, caller must handle errors
std::string* readFile(const std::string& filename, int* errorCode) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        *errorCode = -1;  // File not found
        return nullptr;
    }

    std::string* content = new std::string;
    if (!std::getline(file, *content)) {
        *errorCode = -2;  // Read error
        delete content;    // Manual cleanup!
        return nullptr;
    }

    *errorCode = 0;  // Success
    return content;
}

int main() {
    int errorCode;
    std::string* data = readFile("data.txt", &errorCode);

    if (!data) {
        switch (errorCode) {
            case -1: std::cerr << "Error: File not found\n"; break;
            case -2: std::cerr << "Error: Read failed\n"; break;
            default: std::cerr << "Unknown error\n";
        }
        return 1;
    }

    std::cout << "File content: " << *data << "\n";
    delete data;  // Manual cleanup!
    return 0;
}