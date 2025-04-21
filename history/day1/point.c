#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct { float x, y; } Point;

float distance(Point p1, Point p2) {
    return sqrtf((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

Point midpoint(Point p1, Point p2) {
    Point mid;
    mid.x = (p1.x + p2.x) / 2;
    mid.y = (p1.y + p2.y) / 2;
    return mid;
}

Point addPoints(Point p1, Point p2) {
    Point result;
    result.x = p1.x + p2.x;
    result.y = p1.y + p2.y;
    return result;
}

Point subtractPoints(Point p1, Point p2) {
    Point result;
    result.x = p1.x - p2.x;
    result.y = p1.y - p2.y;
    return result;
}

float dotProduct(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y;
}


int main() {
    Point p1 = {3.0, 4.0};
    Point p2 = {6.0, 8.0};
    
    printf("Distance: %.2f\n", distance(p1, p2));
    
    Point mid = midpoint(p1, p2);
    printf("Midpoint: (%.2f, %.2f)\n", mid.x, mid.y);
    
    Point sum = addPoints(p1, p2);
    printf("Addition: (%.2f, %.2f)\n", sum.x, sum.y);
    
    Point diff = subtractPoints(p1, p2);
    printf("Subtraction: (%.2f, %.2f)\n", diff.x, diff.y);

    printf("Dot Product: %.2f\n", dotProduct(p1, p2));

    
    Point points[] = { {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0} };
    int n = sizeof(points) / sizeof(Point);
    printf("Array of points: ");
    for (int i = 0; i < n; i++) {
        printf("(%f, %f) ", points[i].x, points[i].y);
    }
    printf("\n");
    
    int numPoints = 5;
    Point *dynamicPoints = (Point *)malloc(numPoints * sizeof(Point));
    if (dynamicPoints == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the array with some values
    for (int i = 0; i < numPoints; i++) {
        dynamicPoints[i].x = i * 1.0;
        dynamicPoints[i].y = i * 2.0;
    }

    printf("Dynamic array of points: ");
    for (int i = 0; i < numPoints; i++) {
        printf("(%f, %f) ", dynamicPoints[i].x, dynamicPoints[i].y);
    }
    printf("\n");

    free(dynamicPoints);

    return 0;
}
