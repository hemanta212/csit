// WAP to compare the age of three persons and display the information of elder
// one. Use "this" pointer to return the information of the person

#include <iostream>
using namespace std;

class person {
private:
  int age;
  const char *name;

public:
  person(const char *name_, int age_) : age(age_), name(name_) {}
  int get_age() { return this->age; }
  const char *get_name() { return this->name; }
};

void print_person_info(person &p) {
  std::cout << "Name: " << p.get_name() << "\n"
            << "Age: " << p.get_age() << endl;
}

void compare_and_get_info(person &p1, person &p2, person &p3) {
  int age1 = p1.get_age(), age2 = p2.get_age(), age3 = p3.get_age();
  if (age1 > age2 && age1 > age3) {
    print_person_info(p1);
  } else if (age2 > age1 && age2 > age3) {
    print_person_info(p2);
  } else {
    print_person_info(p3);
  }
}

int main() {
  person p1("A", 10), p2("Bog", 40), p3("C", 18);
  compare_and_get_info(p1, p2, p3);
  return 0;
}
