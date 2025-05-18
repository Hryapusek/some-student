#include <iostream>
#include <optional>
#include <string>
#include <set>

// Task 1: Implement a Student Manager using std::set
class StudentManager
{
 public:
  struct Student
  {
    int id;
    std::string name;
    double gpa;

    bool operator<(Student const& other) const
    {  // вот об этом set знает на момент когда ты его используешь
      return id < other.id;
    }
  };

 private:
  std::set<Student> m_students;

 public:
  // StudentManager() {}; // C++03
  StudentManager() = default;  // C++11
  ~StudentManager() = default;

  // Task 2: Add student (return false if ID exists)
  bool addStudent(int id, std::string const& name, double gpa)
  {
    Student s {id, name, gpa};
    return this->m_students.insert(s).second;  // std::move?
  }

  // Task 3: Remove student by ID
  bool removeStudent(int id)
  {
    Student s {.id = id};
    return this->m_students.erase(s) == 1;
  }

  // Task 4: Find student by ID
  std::pair<Student, bool> findStudent(int id) const
  {
    Student s {.id = id};  // C++17
    std::set<Student>::iterator it = this->m_students.find(s);
    std::pair<Student, bool> psb {s, false};
    if(it != this->m_students.end()) {
      psb.first = *it;
      psb.second = true;
    }
    return psb;
  }

  // Task 4: Find student by ID
  std::pair<Student, bool> findStudentAnother(int id) const
  {
    Student s {.id = id};  // C++17
    std::set<Student>::iterator it = this->m_students.find(s);
    if(it != this->m_students.end()) {
      return std::pair<Student, bool> {*it, true};
    }
    return std::pair<Student, bool> {{}, false};
  }

  std::optional<Student> findStudentAnother1(int id) const
  {
    Student s {.id = id};  // C++17
    std::set<Student>::iterator it = this->m_students.find(s);
    if(it != this->m_students.end()) {
      return *it;
    }
    return std::nullopt;
  }

  // Task 5: Print all students sorted by ID
  void printAll() const {
    for (const Student &s : this->m_students)
    {
        std::cout << "Student name: " << s.name << "\n";
    }
    std::cout.flush();
  }

  // Task 6: Get students with GPA >= threshold
  void printHighAchievers(double min_gpa) const {}

  // Task 7: Merge two student managers
  void merge(StudentManager const& other) {}

  // Task 8: Get class average GPA
  double getAverageGPA() const {}
};

int main()
{
  StudentManager cs101;

  // Test Task 2
  cs101.addStudent(1'001, "Alice", 3.8);
  cs101.addStudent(1'002, "Bob", 3.5);
  cs101.addStudent(1'003, "Charlie", 3.9);

  // Test Task 3
  cs101.removeStudent(1'002);

  // Test Task 4
  cs101.findStudent(1'001);
  cs101.findStudent(1'002);

  // Test Task 5
  std::cout << "\nAll students:\n";
  cs101.printAll();

  // Test Task 6
  std::cout << "\nHigh achievers (GPA >= 3.8):\n";
  cs101.printHighAchievers(3.8);

  // Test Task 7
  StudentManager extra;
  extra.addStudent(1'004, "Diana", 4.0);
  extra.addStudent(1'005, "Eve", 3.7);
  cs101.merge(extra);

  std::cout << "\nAfter merge:\n";
  cs101.printAll();

  std::optional<StudentManager::Student> res =  cs101.findStudentAnother1(20);

  if (res) {
    std::cout << "Found student " << res->name << "\n";
  }

  // Test Task 8
  std::cout << "\nClass average GPA: " << cs101.getAverageGPA() << "\n";

  return 0;
}
