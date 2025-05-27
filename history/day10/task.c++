#include <iostream>
#include <memory>
#include <vector>

class Student {
public:
  Student(std::string name) : m_name(name) {
    std::cout << "Student " << name << " created\n";
  }

  ~Student() { std::cout << "Student " << m_name << " destroyed\n"; }

  void enroll(std::weak_ptr<class Course> course);

private:
  std::string m_name;
  std::vector<std::weak_ptr<class Course>> courses;
};

class Course {
public:
  Course(std::string title) : title(title) {
    std::cout << "Course " << title << " created\n";
  }

  ~Course() {
    std::cout << "Course " << title << " destroyed\n";
    // Dangerous raw pointer cleanup!
    // for (auto student : students) {
    //   delete student;
    // }
  }

  void addStudent(std::shared_ptr<Student> student) {
    students.push_back(student);
  }

private:
  std::string title;
  std::vector<std::shared_ptr<Student>> students;
};

void Student::enroll(std::weak_ptr<class Course> course) {
  courses.push_back(course);
  // auto v = std::shared_ptr<Student>(this); // ! SEGFAULT!
  // course->addStudent(this); // This could never be done (for a while)
  // this -> shared_ptr<Student>
}

void foo(std::vector<int> &&vec) {}

int main() {
  std::vector vec{1, 2, 3};
  // foo(vec); // Compile error
  std::vector<int>{1, 2, 3};
  foo(std::vector<int>{1, 2, 3});
  foo(std::move(vec));
  // vec is not valid anymore

  // Current problematic usage
  std::shared_ptr<Student> shared_alice;
  {
    std::unique_ptr<Student> alice =
        std::make_unique<Student>("Alice"); //   new Student("Alice");
    shared_alice = std::shared_ptr<Student>(std::move(alice));
  }
  // std::unique_ptr<Student> alice2 = alice; // ! NO COPY
  // std::unique_ptr<Student> alice1 = std::unique_ptr<Student>(new
  // Student("Alice"));//   new Student("Alice");
  std::shared_ptr<Course> math =
      std::shared_ptr<Course>(new Course("Mathematics"));
  
  // clang-format off
  // math->addStudent(std::shared_ptr<Student>(std::move(alice))); // Алиса потеряна
  // Неявное преобразование std::shared_ptr<Student>(std::unique_ptr<Student>&& ptr)
  // unique_ptr -> shared_ptr Передача владения 
  // Обратно не получится!
  // clang-format on

  math->addStudent(shared_alice);

  (shared_alice.get())->enroll(math); // SAME AS alice->enroll(math);

  // Memory leak - who should delete these?
  // delete alice;
  // delete math;

  return 0;
}
