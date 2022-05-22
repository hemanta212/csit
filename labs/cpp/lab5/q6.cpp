// WAP to read information of three employees (name, address and salary). Make
// three separae classes for each employee. Now calculate the total salary of
// three and display all information. Use concept of friend function.

#include <iostream>
using namespace std;

class Emp2;
class Emp3;

class Emp1 {
  char name[10];
  char address[10];
  int salary;

public:
  Emp1() {}
  void get_info() {
    cout << "Give info for employee 1\nName: ";
    cin >> name;
    cout << "\nAddress: ";
    cin >> address;
    cout << "\nSalary: ";
    cin >> salary;
  }

  friend void total_salary_and_info(Emp1 &, Emp2 &, Emp3 &);
};

class Emp2 {
  char name[10];
  char address[10];
  int salary;

public:
  Emp2() {}
  void get_info() {
    cout << "Give info for employee 2\nName: ";
    cin >> name;
    cout << "Address: ";
    cin >> address;
    cout << "Salary: ";
    cin >> salary;
  }

  friend void total_salary_and_info(Emp1 &, Emp2 &, Emp3 &);
};

class Emp3 {
  char name[10];
  char address[10];
  int salary;

public:
  Emp3() {}
  void get_info() {
    cout << "\nGive info for employee 3\nName: ";
    cin >> name;
    cout << "Address: ";
    cin >> address;
    cout << "Salary: ";
    cin >> salary;
  }
  friend void total_salary_and_info(Emp1 &, Emp2 &, Emp3 &);
};

void total_salary_and_info(Emp1 &e1, Emp2 &e2, Emp3 &e3) {
  cout << "Name: " << e1.name << " Address: " << e1.address
       << " Salary: " << e1.salary << endl;
  cout << "Name: " << e2.name << " Address: " << e2.address
       << " Salary: " << e2.salary << endl;
  cout << "Name: " << e3.name << " Address: " << e3.address
       << " Salary: " << e3.salary << endl;

  cout << "\nTotal Salary is: " << e1.salary + e2.salary + e3.salary << endl;
}

int main() {
  Emp1 e1;
  Emp2 e2;
  Emp3 e3;
  e1.get_info();
  e2.get_info();
  e3.get_info();
  total_salary_and_info(e1, e2, e3);
  return 0;
}
