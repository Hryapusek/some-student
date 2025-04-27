#include <iostream>
#include <stdexcept>

class ArrayRAII {
public:
    ArrayRAII(size_t size) : size_(size), data_(new int[size]) {
        std::cout << "Array allocated with size " << size_ << std::endl;
    }

    ~ArrayRAII() {
        delete[] data_;
        std::cout << "Array deallocated" << std::endl;
    }

    int& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }

    int* release() {
        int* temp = data_;
        data_ = nullptr;
        return temp;
    }

    size_t size() const {
        return size_;
    }

private:
    size_t size_;
    int* data_;
};

int main() {
    try {
        ArrayRAII array(5);
        array[0] = 10;
        array[1] = 20;
        std::cout << "First element: " << array[0] << std::endl;
        std::cout << "Second element: " << array[1] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}

