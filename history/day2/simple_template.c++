#include <iostream>

// Simple template example
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Example usage
int main() {
    std::cout << max(3, 7) << std::endl;  // 7
    std::cout << max(3.5, 1.5) << std::endl;  // 3.5
    std::cout << max("hello", "world") << std::endl;  // world
    return 0;
}
