// Write a program to overload function template
#include <iostream>
using namespace std;

template <class T1> void print_number(T1 a) {
  cout << "Template function argument: " << a << endl;
}

void print_number(int a) { cout << "Ordinary Function args: " << a << endl; }

int main() {
  print_number(2);
  print_number(2.3);
  print_number(2.4f);
  return 0;
}
