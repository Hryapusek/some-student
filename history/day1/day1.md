# 21.04.2025
Transition from C point to C++ point

```c
typedef struct { float x, y; } Point;
float distance(Point p1, Point p2);
```

```c++
#include <cmath>
#include <iostream>

class Point {
private:
    float x, y;  // Encapsulated data
public:
    // Constructor (initialization list)
    Point(float x = 0, float y = 0) : x(x), y(y) {}

    // Method to calculate distance (const-correct)
    float distanceTo(const Point& other) const {
        return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
    }

    // Getters (const-correct)
    float getX() const { return x; }
    float getY() const { return y; }
};
```

