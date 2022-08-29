// Write a program to show the concept of static function and static member
// variable

#include <iostream>

using namespace std;

class Person {
  const char *name;

public:
  Person(const char *name_) : name(name_) {}
  void print_name() { cout << "Name: " << name << endl; }
  virtual ~Person() { cout << "Person destroyed" << endl; }
};

class Student : public Person {
public:
  Student(const char *name_) : Person(name_) {}
  ~Student() { cout << "Student destroyed" << endl; }
};

int main() {
  {
    Student s("S");
    Person *p;
    p = &s;
    p->print_name();
  }
  return 0;
}
