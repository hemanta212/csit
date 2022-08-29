// Write a program to show the concept of static function and static member
// variable

#include <iostream>

using namespace std;

class Person {
  const char *name;
  static int count;

public:
  Person(const char *name_) : name(name_) {}
  const char *get_name() { return name; }
  void increment_count() { count++; }
  static void print_count() { cout << "Count is : " << count << endl; }
};

int Person::count;

int main() {
  Person p("A"), q("B");
  Person::print_count();
  p.increment_count();

  q.print_count();

  Person r("D");
  r.print_count();
  r.increment_count();

  Person::print_count();
  return 0;
}
