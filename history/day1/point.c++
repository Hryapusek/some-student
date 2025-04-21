#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <cassert>  // For debugging

class Point {
private:
    float x, y;

public:
    // Constructor with default values (initializer list)
    Point(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    // Getters (const-correct)
    float getX() const { return x; }
    float getY() const { return y; }

    // Setters (with validation)
    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }

    // --- Operations as methods ---
    float distanceTo(const Point& other) const {
        return std::hypot(other.x - x, other.y - y);  // More accurate than sqrt(pow)
    }

    Point midpointWith(const Point& other) const {
        return Point((x + other.x) / 2, (y + other.y) / 2);
    }

    // --- Operator Overloading ---
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    float dotProduct(const Point& other) const {
        return x * other.x + y * other.y;
    }

    // --- Friend function for printing ---
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    // Stack-allocated points
    Point p1(3.0f, 4.0f);
    Point p2(6.0f, 8.0f);

    std::cout << "Distance: " << p1.distanceTo(p2) << "\n";
    std::cout << "Midpoint: " << p1.midpointWith(p2) << "\n";
    std::cout << "Addition: " << p1 + p2 << "\n";
    std::cout << "Subtraction: " << p1 - p2 << "\n";
    std::cout << "Dot Product: " << p1.dotProduct(p2) << "\n";

    // Static array → std::array (fixed size)
    std::array<Point, 4> points = { Point(1.0f, 2.0f), Point(3.0f, 4.0f), 
                                   Point(5.0f, 6.0f), Point(7.0f, 8.0f) };

    std::cout << "Array of points: ";
    for (const auto& p : points) {
        std::cout << p << " ";
    }
    std::cout << "\n";
    // Dynamic array → std::vector (resizable)
    std::vector<Point> dynamicPoints;
    dynamicPoints.reserve(5);  // Optional: pre-allocate

    for (int i = 0; i < 5; ++i) {
        dynamicPoints.emplace_back(i * 1.0f, i * 2.0f);  // In-place construction
    }

    std::cout << "Dynamic array of points: ";
    for (const auto& p : dynamicPoints) {
        std::cout << p << " ";
    }
    std::cout << "\n";

    // No manual free() needed! std::vector handles it.

    return 0;
}
