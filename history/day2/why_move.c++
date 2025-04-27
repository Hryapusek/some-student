#include <iostream>
#include <cstring>

class SimpleVector {
private:
    int* data;
    size_t size;
public:
    // Constructor
    SimpleVector(size_t n) : size(n), data(new int[n]) {
        std::cout << "Constructed (" << size << " elements)\n";
    }

    // Copy Constructor (Expensive!)
    SimpleVector(const SimpleVector& other) : size(other.size), data(new int[other.size]) {
        std::memcpy(data, other.data, size * sizeof(int));
        std::cout << "Copied (" << size << " elements)\n";
    }
    
    // Copy assignment operator
    SimpleVector& operator=(const SimpleVector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::memcpy(data, other.data, size * sizeof(int));
            std::cout << "Copied (" << size << " elements)\n";
        }
        return *this;
    }

    void print() const {
        std::cout << "Vector (" << size << " elements): ";
    }

    // Destructor
    ~SimpleVector() {
        std::cout << "Destroyed\n";
    }
};

// Function that returns a vector (creates a copy)
SimpleVector createVector() {
    SimpleVector vec(1'000'000);  // 1M elements
    return vec;  // Oops: Copy triggered without move semantics!
}

int main() {
    SimpleVector v(1);
    v = createVector();  // Copy happens here!
    v.print();
    return 0;
}
