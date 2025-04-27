#include <iostream>

double divide(int a, int b, bool& success) {
    if (b == 0) {
        success = false;
        return 0;
    }
    success = true;
    return static_cast<double>(a) / b;
}

int main() {
    bool success;
    divide(10, 2, success);
    if (!success) {
        std::cerr << "Division by zero error" << std::endl;
    }

    divide(10, 0, success);
    if (!success) {
        std::cerr << "Division by zero error" << std::endl;
    }

    return 0;
}

