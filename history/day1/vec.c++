#include <iostream>
#include <cassert>  // For bounds checking
#include <vector>
#include <map>

// .h
template <typename T>
class SimpleVector {
private:
    T* data;         // Raw pointer to the array (just like in C)
    size_t size;     // Current number of elements
    size_t capacity; // Total allocated capacity
};

class SimpleVector {
private:
    int* data;         // Raw pointer to the array (just like in C)
    size_t size;     // Current number of elements
    size_t capacity; // Total allocated capacity
};

class SimpleVector {
private:
    float* data;         // Raw pointer to the array (just like in C)
    size_t size;     // Current number of elements
    size_t capacity; // Total allocated capacity
};

// main.cpp
int main()
{
    SimpleVector<float> v1;
    SimpleVector<int> v2;

    std::vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);
    std::map<int, int> s = {{1, 2}, {3, 4}, {5, 6}};
}
