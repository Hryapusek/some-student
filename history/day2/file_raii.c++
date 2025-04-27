#include <iostream>

class File {
public:
    File(const char* filename) : filename_(filename) {
        file_ = fopen(filename, "r");
        if (file_ == nullptr) {
            throw std::runtime_error("Could not open file");
        }
    }

    ~File() {
        if (file_ != nullptr) {
            fclose(file_);
        }
    }

    char readChar() {
        int c = fgetc(file_);
        if (c == EOF) {
            throw std::runtime_error("Could not read from file");
        }
        return static_cast<char>(c);
    }

private:
    const char* filename_;
    FILE* file_;
};

int main() {
    try {
        File file("example.txt");
        char c = file.readChar();
        std::cout << c << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
