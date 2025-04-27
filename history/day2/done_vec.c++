#include <iostream>
#include <cassert>  // For bounds checking

template <typename T>
class SimpleVector {
private:
    T* data;         // Raw pointer to the array (just like in C)
    size_t size;     // Current number of elements
    size_t capacity; // Total allocated capacity

public:
    // Constructor
    SimpleVector() : data(nullptr), size(0), capacity(0) {}

    // Copy constructor
    SimpleVector(const SimpleVector& other) : data(nullptr), size(0), capacity(0) {
        *this = other;
    }

    // Move constructor
    SimpleVector(SimpleVector&& other) : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // Destructor (cleans up memory)
    ~SimpleVector() {
        delete[] data;  // Just like free() in C, but type-aware
    }

    // Copy assignment operator
    SimpleVector& operator=(const SimpleVector& other) {
        if (this != &other) {
            delete[] data;  // Clean up old data
            data = nullptr;
            size = 0;
            capacity = 0;

            if (other.size > 0) {
                capacity = other.capacity;
                data = new T[capacity];
                for (size_t i = 0; i < other.size; ++i) {
                    data[i] = other.data[i];
                }
                size = other.size;
            }
        }
        return *this;
    }

    // Move assignment operator
    SimpleVector& operator=(SimpleVector&& other) {
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
        return *this;
    }

    // Add an element to the end
    void push_back(const T& value) {
        if (size >= capacity) {
            // Resize (like realloc in C, but safer)
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T* new_data = new T[capacity];  // Allocate new array
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];      // Copy old data
            }
            delete[] data;                  // Free old array
            data = new_data;
        }
        data[size++] = value;               // Add the new element
    }

    // Access element (with bounds checking)
    T& operator[](size_t index) {
        assert(index < size && "Index out of bounds!");
        return data[index];
    }

    // Get current size
    size_t getSize() const { return size; }

    // Print all elements (for debugging)
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    SimpleVector<int> vec;

    // Add elements (push_back handles resizing)
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // Access elements (like an array)
    std::cout << "First element: " << vec[0] << "\n";  // 10

    // Print all
    vec.print();  // 10 20 30

    // Memory is automatically freed when `vec` goes out of scope!
    return 0;
}