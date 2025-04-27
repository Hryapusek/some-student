#include <cstddef>

template <typename T>
class SimpleVector {
private:
    T* m_data;               // Raw pointer to the array (just like in C)
    size_t m_size;           // Current number of elements
    size_t m_capacity;       // Total allocated capacity

public:
    // Constructor
    SimpleVector();

    // Copy constructor
    SimpleVector(const SimpleVector& other);

    // Move constructor
    SimpleVector(SimpleVector&& other);

    // Destructor
    ~SimpleVector();

    // Copy assignment operator
    SimpleVector& operator=(const SimpleVector& other);

    // Move assignment operator
    SimpleVector& operator=(SimpleVector&& other);

    // Add an element to the end
    void push_back(const T& value);

    // Get current size
    size_t size() const;

    // Print all elements (for debugging)
    void print() const;
};

