#include <iostream>
#include <set>
#include <string>
#include <algorithm>

// Task 1: Implement a Student Manager using std::set
class StudentManager {
private:
    struct Student {
        int id;
        std::string name;
        double gpa;
    };

public:
    // Task 2: Add student (return false if ID exists)
    bool addStudent(int id, const std::string& name, double gpa) {
    }

    // Task 3: Remove student by ID
    bool removeStudent(int id) {
    }

    // Task 4: Find student by ID
    void findStudent(int id) const {
    }

    // Task 5: Print all students sorted by ID
    void printAll() const {
    }

    // Task 6: Get students with GPA >= threshold
    void printHighAchievers(double min_gpa) const {
    }

    // Task 7: Merge two student managers
    void merge(const StudentManager& other) {
    }

    // Task 8: Get class average GPA
    double getAverageGPA() const {
    }
};

int main() {
    StudentManager cs101;

    // Test Task 2
    cs101.addStudent(1001, "Alice", 3.8);
    cs101.addStudent(1002, "Bob", 3.5);
    cs101.addStudent(1003, "Charlie", 3.9);

    // Test Task 3
    cs101.removeStudent(1002);

    // Test Task 4
    cs101.findStudent(1001);
    cs101.findStudent(1002);

    // Test Task 5
    std::cout << "\nAll students:\n";
    cs101.printAll();

    // Test Task 6
    std::cout << "\nHigh achievers (GPA >= 3.8):\n";
    cs101.printHighAchievers(3.8);

    // Test Task 7
    StudentManager extra;
    extra.addStudent(1004, "Diana", 4.0);
    extra.addStudent(1005, "Eve", 3.7);
    cs101.merge(extra);

    std::cout << "\nAfter merge:\n";
    cs101.printAll();

    // Test Task 8
    std::cout << "\nClass average GPA: " << cs101.getAverageGPA() << "\n";

    return 0;
}